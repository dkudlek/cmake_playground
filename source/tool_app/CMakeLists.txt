
add_executable(tool_app
  main.cpp
)

target_link_libraries(tool_app
  PRIVATE ${PROJECT_NAME}::state_machine testbed_compiler_flags
)

target_include_directories(
  tool_app PUBLIC "${PROJECT_BINARY_DIR}" ${state_machine_SOURCE_DIR}
)

add_test(NAME tool_app
  COMMAND tool_app)

install(TARGETS tool_app DESTINATION bin)
