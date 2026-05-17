add_executable(test_npcap_send send_pakage.c)

target_link_libraries(test_npcap_send PRIVATE unique_tcp)

if(WIN32)
  target_link_libraries(test_npcap_send PRIVATE Ws2_32)
endif()
