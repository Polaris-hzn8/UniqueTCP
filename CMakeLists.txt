cmake_minimum_required(VERSION 3.16)

project(UniqueTCP C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(NOT DEFINED UniqueTCP_NPCAP_ROOT)
  set(UniqueTCP_NPCAP_ROOT "${CMAKE_SOURCE_DIR}/npcap")
endif()

add_subdirectory(src/unique_tcp)
add_subdirectory(src/apps)
add_subdirectory(test)
