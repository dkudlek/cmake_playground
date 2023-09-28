Cmake Playground
====
[TOC]

# TL:DR

Setup googletest 

```sh
git clone https://github.com/google/googletest.git -b v1.14.0
cd googletest        # Main directory of the cloned repository.
mkdir build          # Create a directory to hold the build output.
cd build 
#IF WIN
cmake .. -DCMAKE_INSTALL_PREFIX=../install -Dgtest_force_shared_crt=1  # Set install folder to PROJECT_ROOT/install
#ELSE
cmake .. -DCMAKE_INSTALL_PREFIX=../install 
#ENDIF
cmake --build . --config Release --target install  # Build release and trigger install procedure
cd ..
```

Setup cmake_playground
```sh 
mkdir build          # Create a directory to hold the build output.
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=../install # Set install folder to PROJECT_ROOT/install
cmake --build . --config Release --target install  # Build release and trigger install procedure
ctest -C Release --verbose
```

```sh
# setup docker in gitlab runner on synolog
cd /tmp
mkdir docker
cd docker
curl https://hub.docker.com/r/bebuch/gcc-gtest/dockerfile > Dockerfile
sudo docker build -t bebuch/gcc-gtest .
```


# Overview

```puml
@startuml
rectangle third_party_lib
rectangle lib_function
rectangle application
third_party_lib <- lib_function
lib_function <- application
@enduml
```
```
Folder structure:
- third_party_lib
- root
-- build
-- source
--- lib_function
--- wrapper
---- app
----- application
```


# *.config
[example](https://github.com/roboception/rc_dynamics_api/blob/master/cmake/PROJECTConfig.cmake.in)
[how-to create *.config](https://gitlab.kitware.com/cmake/community/-/wikis/doc/tutorials/How-to-create-a-ProjectConfig.cmake-file)


# Steps
1. Setup the standard project files

    ```make
    cmake_minimum_required(VERSION 3.4 FATAL_ERROR)
    project(CMakeTestBed LANGUAGES CXX)

    set(CMAKETESTBED_MAJOR_VERSION 0)
    set(CMAKETESTBED_MINOR_VERSION 1)
    set(CMAKETESTBED_PATCH_VERSION 0)
    set(CMAKETESTBED_VERSION
      ${CMAKETESTBED_MAJOR_VERSION}.${CMAKETESTBED_MINOR_VERSION}.${CMAKETESTBED_PATCH_VERSION})
    message("[CMAKETESTBED_VERSION] ${CMAKETESTBED_VERSION}")
    ```
2. Setup the standard INSTALL PATHs

    ```make
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
    ```
3. Set up include directories

    ```cmake
    set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/source)
    # set up include-directories
    include_directories(
     "${PROJECT_SOURCE_DIR}"
     "${PROJECT_BINARY_DIR}")
    # print include directories
    get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
    foreach(dir ${dirs})
     message(STATUS "dir='${dir}'")
    endforeach()
    ```


    - To import the header ``foo1.h`` from ``test_lib`` in ``tool``, you have to specify the included header relative to ``include_directories``.
    - In this case we changed the ``${PROJECT_SOURCE_DIR}`` to ``${PROJECT_SOURCE_DIR}/source``.
    - This is important for the chosen folder structure and to use ``foo`` by an external programs
    - ``Foo1.h`` is located at ``${PROJECT_SOURCE_DIR}/source/test_lib``  E.g. ``#include "test_lib/foo1.h"``



# CI

https://easysolutionsit.de/artikel/gitlab-ci.html

- Download ``gitlab/gitlab-runner`` docker image
- Create network
- Create config file
- start docker from ssh (to access docker.sock)


run runner from ssh:

```bash
docker run -d -p 9000:9000 --name runner.vnet.kudlek.online --restart always -v /var/run/docker.sock:/var/run/docker.sock -v volume1/docker_gitlab/runner/runner0/data:/etc/gitlab-runner --network=gitlab-runner gitlab/gitlab-runner
```
