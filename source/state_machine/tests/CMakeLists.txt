find_package(GTest REQUIRED)

add_executable(state_machine_test test.cpp)

target_link_libraries(state_machine_test ${PROJECT_NAME}::state_machine GTest::GTest GTest::Main)
target_include_directories(
  state_machine_test PUBLIC "${PROJECT_BINARY_DIR}" ${state_machine_SOURCE_DIR}
)
gtest_add_tests(TARGET state_machine_test
  TEST_SUFFIX .noArgs
  TEST_LIST noArgsTests
)

set_tests_properties(${noArgsTests} PROPERTIES TIMEOUT 10)
