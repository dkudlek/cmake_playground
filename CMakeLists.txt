cmake_minimum_required(VERSION 3.4 FATAL_ERROR)
project(CMakeTestBed LANGUAGES CXX)

set(CMAKETESTBED_MAJOR_VERSION 0)
set(CMAKETESTBED_MINOR_VERSION 1)
set(CMAKETESTBED_PATCH_VERSION 0)
set(CMAKETESTBED_VERSION
  ${CMAKETESTBED_MAJOR_VERSION}.${CMAKETESTBED_MINOR_VERSION}.${CMAKETESTBED_PATCH_VERSION})
message("[CMAKETESTBED_VERSION] ${CMAKETESTBED_VERSION}")


# Setup basic install PATHs for lib, bin, include and CMake
set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_BIN_DIR bin CACHE PATH "Installation directory for executables")
set(INSTALL_INCLUDE_DIR include CACHE PATH
  "Installation directory for header files")
if(WIN32 AND NOT CYGWIN)
  set(DEF_INSTALL_CMAKE_DIR CMake)
else()
  set(DEF_INSTALL_CMAKE_DIR lib/CMake/${CMAKE_PROJECT_NAME})
endif()
set(INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH
  "Installation directory for CMake files")

# Make relative install paths absolute (needed later on)
foreach(p LIB BIN INCLUDE CMAKE)
  message("For ${p} in (LIB, BIN, INCLUDE, CMAKE)")
  set(var INSTALL_${p}_DIR)
  message("[basic install path] ${${var}}")
  if(NOT IS_ABSOLUTE "${${var}}")
    # message("${CMAKE_INSTALL_PREFIX}/${${var}}")
    set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
    message("[absolute install path] ${${var}}")
  endif()
endforeach()

# set up include-directories
include_directories(
  "${PROJECT_SOURCE_DIR}"
  "${PROJECT_BINARY_DIR}")


# Targets that we develop here
add_subdirectory(source)

export(PACKAGE CMakeTestBed)
