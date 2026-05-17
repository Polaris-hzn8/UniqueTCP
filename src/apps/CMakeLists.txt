file(GLOB ECHO_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/echo/*.c")
file(GLOB PING_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/ping/*.c")

add_executable(unique_tcp_demo
  ${ECHO_SOURCES}
  ${PING_SOURCES}
  main.c
  download.c
)

target_include_directories(unique_tcp_demo PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(unique_tcp_demo PRIVATE unique_tcp)

if(WIN32)
  target_link_libraries(unique_tcp_demo PRIVATE Ws2_32)
endif()
