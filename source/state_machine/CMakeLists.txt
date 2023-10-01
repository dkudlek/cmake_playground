add_library(state_machine state_machine.h state_machine.cpp)
add_library(${PROJECT_NAME}::state_machine ALIAS state_machine)

target_include_directories(state_machine
                           INTERFACE 
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                           $<INSTALL_INTERFACE:include>
                           )
target_link_libraries(state_machine PUBLIC testbed_compiler_flags)

if(${BUILD_SHARED_LIBS})
  target_compile_definitions(state_machine PRIVATE "EXPORTING_STATE_MACHINE")
  target_compile_definitions(state_machine PRIVATE "BUILD_SHARED")
endif()

get_target_property(MAIN_CFLAGS state_machine COMPILE_DEFINITIONS)
message("-- Target compiler flags are: ${MAIN_CFLAGS}")

install(
  TARGETS state_machine testbed_compiler_flags
  EXPORT state_machine_targets
  DESTINATION lib)
install(FILES state_machine.h DESTINATION include)

add_subdirectory(tests)