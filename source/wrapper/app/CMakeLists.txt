
add_executable(tool
  main.cpp
)

target_link_libraries(tool
  PRIVATE state_machine
)

install(TARGETS tool
  # IMPORTANT: Add the bar executable to the "export-set"
  EXPORT CMakeTestBedTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin)
