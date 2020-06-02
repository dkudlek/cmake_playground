
add_executable(tool
  main.cpp
)
add_executable(my::tool ALIAS tool)
target_link_libraries(tool
  PRIVATE foo
)
