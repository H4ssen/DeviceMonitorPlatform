qt_add_executable(DeviceMonitorPlatform main.cpp)

target_link_libraries(DeviceMonitorPlatform PRIVATE UI)

add_subdirectory(ui)
add_subdirectory(domain)
add_subdirectory(infra)
add_subdirectory(app)