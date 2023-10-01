
add_executable(tool_app
  main.cpp
)

target_link_libraries(tool_app
  PRIVATE ${PROJECT_NAME}::state_machine testbed_compiler_flags
)

target_include_directories(
  tool_app PUBLIC "${PROJECT_BINARY_DIR}" ${state_machine_SOURCE_DIR}
)

install(TARGETS tool_app DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/cmake_test_bed_version.h"
  DESTINATION include
  )
