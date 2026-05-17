file(GLOB NET_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/net/*.c")
file(GLOB PLATFORM_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/platform/*.c")

add_library(unique_tcp SHARED ${NET_SOURCES} ${PLATFORM_SOURCES})

target_include_directories(unique_tcp PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/unique_tcp>"
  "$<BUILD_INTERFACE:${UniqueTCP_NPCAP_ROOT}/Include>"
)

target_compile_definitions(unique_tcp PUBLIC NET_DRIVER_PCAP)

if(WIN32)
  target_compile_definitions(unique_tcp PUBLIC SYS_PLAT_WINDOWS)
  if(MSVC)
    target_compile_definitions(unique_tcp PRIVATE _CRT_SECURE_NO_WARNINGS)
    set_target_properties(unique_tcp PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
    target_link_options(unique_tcp PRIVATE /EXPORT:netdev_ops)
  endif()
  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    target_link_directories(unique_tcp PUBLIC "${UniqueTCP_NPCAP_ROOT}/Lib/x64")
  else()
    target_link_directories(unique_tcp PUBLIC "${UniqueTCP_NPCAP_ROOT}/Lib")
  endif()
  target_link_libraries(unique_tcp PUBLIC wpcap Packet Ws2_32)
else()
  if(APPLE)
    target_compile_definitions(unique_tcp PUBLIC SYS_PLAT_MAC)
  else()
    target_compile_definitions(unique_tcp PUBLIC SYS_PLAT_LINUX)
  endif()
  target_link_libraries(unique_tcp PUBLIC pthread pcap)
endif()
