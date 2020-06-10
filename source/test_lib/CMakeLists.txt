add_library(foo STATIC
  foo1.h
  foo1.cpp
  foo2.cpp
)
add_library(my::foo ALIAS foo)
# makes the headers available (in this case, the header file lies in this directory, so we use".")
# if your headers are in a subfolder include then write: ...(foo PUBLIC include)
# target_include_directories(foo PUBLIC .)

set_target_properties(foo PROPERTIES
PUBLIC_HEADER "foo1.h")


export(TARGETS foo
  FILE "${PROJECT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.cmake")

install(TARGETS foo
  # IMPORTANT: Add the foo library to the "export-set"
  EXPORT CMakeTestBedTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
  LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
  PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/foo"
    COMPONENT dev)
message("INSTALL_INCLUDE_DIR ${INSTALL_INCLUDE_DIR}")
