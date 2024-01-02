cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(cmake_test_bed LANGUAGES CXX)

set(CMAKETESTBED_VERSION_MAJOR 0)
set(CMAKETESTBED_VERSION_MINOR 1)
set(CMAKETESTBED_VERSION_PATCH 0)
set(CMAKETESTBED_VERSION
  ${CMAKETESTBED_VERSION_MAJOR}.${CMAKETESTBED_VERSION_MINOR}.${CMAKETESTBED_VERSION_PATCH})

# specify the C++ standard
add_library(testbed_compiler_flags INTERFACE)
target_compile_features(testbed_compiler_flags INTERFACE cxx_std_11)

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

# add compiler warning flags just when building this project via
# the BUILD_INTERFACE genex
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(testbed_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

# control where the static and shared libraries are built so that on windows
# we don't need to tinker with the path to run the executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

enable_testing()

configure_file(cmake/cmake_test_bed_version.h.in ${PROJECT_BINARY_DIR}/cmake_test_bed_version.h)

add_subdirectory(source)

install(FILES "${PROJECT_BINARY_DIR}/cmake_test_bed_version.h"
  DESTINATION include
)