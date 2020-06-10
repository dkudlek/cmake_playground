
add_executable(tool
  main.cpp
)
add_executable(my::tool ALIAS tool)
target_link_libraries(tool
  PRIVATE foo
)

install(TARGETS tool
  # IMPORTANT: Add the bar executable to the "export-set"
  EXPORT CMakeTestBedTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin)
