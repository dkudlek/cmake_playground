add_library(state_machine STATIC state_machine.h state_machine.cpp)

set_target_properties(state_machine PROPERTIES PUBLIC_HEADER "state_machine.h")

export(TARGETS state_machine
       FILE "${PROJECT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.cmake")

export(TARGETS state_machine
  FILE "${PROJECT_BINARY_DIR}/CMakeTestBedTargets.cmake")

install(
  TARGETS state_machine
  # IMPORTANT: Add the state_machine library to the "export-set"
  EXPORT CMakeTestBedTargets
  ARCHIVE DESTINATION "${INSTALL_LIB_DIR}"
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
  LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
  PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/state_machine"
                COMPONENT dev)

message("INSTALL_INCLUDE_DIR ${INSTALL_INCLUDE_DIR}")


add_subdirectory(tests)