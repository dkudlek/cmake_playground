find_package(GTest)

add_executable(state_machine_test test.cpp)


target_link_libraries(state_machine_test state_machine GTest::GTest GTest::Main)


gtest_add_tests(TARGET state_machine_test
                TEST_SUFFIX .noArgs
                TEST_LIST   noArgsTests
)

set_tests_properties(${noArgsTests}  PROPERTIES TIMEOUT 10)
