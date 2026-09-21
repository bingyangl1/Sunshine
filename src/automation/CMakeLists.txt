add_library(automation STATIC
  automation_server.cpp
)

target_link_libraries(automation PRIVATE
  sunshine
)

target_include_directories(automation PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)
