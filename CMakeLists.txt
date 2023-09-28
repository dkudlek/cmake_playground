cmake_minimum_required(VERSION 3.4 FATAL_ERROR)
project(CMakeTestBed LANGUAGES CXX)

set(CMAKETESTBED_MAJOR_VERSION 0)
set(CMAKETESTBED_MINOR_VERSION 1)
set(CMAKETESTBED_PATCH_VERSION 0)
set(CMAKETESTBED_VERSION
  ${CMAKETESTBED_MAJOR_VERSION}.${CMAKETESTBED_MINOR_VERSION}.${CMAKETESTBED_PATCH_VERSION})


# Setup basic install PATHs for lib, bin, include and CMake
set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_BIN_DIR bin CACHE PATH "Installation directory for executables")
set(INSTALL_INCLUDE_DIR include CACHE PATH
  "Installation directory for header files")

# Make relative install paths absolute (needed later on)
foreach(p LIB BIN INCLUDE CMAKE)
  set(var INSTALL_${p}_DIR)
  if(NOT IS_ABSOLUTE "${${var}}")
    set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
  endif()
endforeach()

set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/source)
# set up include-directories
include_directories(
  "${PROJECT_SOURCE_DIR}"
  "${PROJECT_BINARY_DIR}")

enable_testing()
# Targets that we develop here
add_subdirectory(source)



export(PACKAGE CMakeTestBed)

# Create the FooBarConfig.cmake and FooBarConfigVersion files
file(RELATIVE_PATH REL_INCLUDE_DIR "${CMAKE_INSTALL_PREFIX}"
   "${INSTALL_INCLUDE_DIR}")
# ... for the build tree
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}")
configure_file(CMakeTestBedConfig.cmake.in
  "${PROJECT_BINARY_DIR}/CMakeTestBedConfig.cmake" @ONLY)
# ... for the install tree
set(CONF_INCLUDE_DIRS "\${CMAKETESTBED_CMAKE_DIR}/${REL_INCLUDE_DIR}")
configure_file(CMakeTestBedConfig.cmake.in
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeTestBedConfig.cmake" @ONLY)
# ... for both
configure_file(CMakeTestBedConfigVersion.cmake.in
  "${PROJECT_BINARY_DIR}/CMakeTestBedVersion.cmake" @ONLY)

# Install the FooBarConfig.cmake and FooBarConfigVersion.cmake
install(FILES
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeTestBedConfig.cmake"
  "${PROJECT_BINARY_DIR}/CMakeTestBedVersion.cmake"
  DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)

# Install the export set for use with the install-tree
install(EXPORT CMakeTestBedTargets DESTINATION
  "${CMAKE_INSTALL_PREFIX}" COMPONENT dev)
