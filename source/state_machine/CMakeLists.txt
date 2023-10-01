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
set_target_properties(state_machine PROPERTIES PUBLIC_HEADER "${HEADER_FILES}")


install(
  TARGETS state_machine testbed_compiler_flags
  EXPORT state_machine_targets
  DESTINATION lib)
install(FILES state_machine.h DESTINATION include)

include(CMakePackageConfigHelpers)

# generate the config file that includes the exports
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/state_machine-config.cmake
  "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}__state_machine-config.cmake"
  INSTALL_DESTINATION "lib/cmake"
  NO_SET_AND_CHECK_MACRO
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
  )

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}__state_machine-config.cmake
  DESTINATION cmake
  )

install(EXPORT state_machine_targets
  FILE ${PROJECT_NAME}__state_machine.cmake
  NAMESPACE ${PROJECT_NAME}:: 
  DESTINATION cmake
  )



add_subdirectory(tests)