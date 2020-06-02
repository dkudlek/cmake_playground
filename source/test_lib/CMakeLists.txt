add_library(foo STATIC
  foo1.h
  foo1.cpp
  foo2.cpp
)
add_library(my::foo ALIAS foo)
# makes the headers available (in this case, the header file lies in this directory, so we use".")
# if your headers are in a subfolder include then write: ...(foo PUBLIC include)
target_include_directories(foo PUBLIC .)

export(TARGETS foo
  FILE "${PROJECT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.cmake")

