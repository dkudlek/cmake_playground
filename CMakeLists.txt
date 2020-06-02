cmake_minimum_required(VERSION 3.4 FATAL_ERROR)
project(CMakeTestBed LANGUAGES CXX)

set(CMakeTestBed_MAJOR_VERSION 0)
set(CMakeTestBed_MINOR_VERSION 1)
set(CMakeTestBed_PATCH_VERSION 0)
set(CMakeTestBed_VERSION
  ${CMakeTestBed_MAJOR_VERSION}.${CMakeTestBed_MINOR_VERSION}.${CMakeTestBed_PATCH_VERSION})


# Make relative paths absolute (needed later on)
foreach(p LIB BIN INCLUDE CMAKE)
  set(var INSTALL_${p}_DIR)
  if(NOT IS_ABSOLUTE "${${var}}")
    set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
  endif()
endforeach()

# set up include-directories
include_directories(
  "${PROJECT_SOURCE_DIR}" 
  "${PROJECT_BINARY_DIR}") 


# Targets that we develop here
add_subdirectory(source)

export(PACKAGE CMakeTestBed)

