cmake_minimum_required(VERSION 3.19)
project(DeviceMonitorPlatform LANGUAGES C CXX)


find_package(Qt6 6.4 REQUIRED COMPONENTS Core Widgets SerialPort SerialBus Network Test)

qt_standard_project_setup()

enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED)


option(ENABLE_COVERAGE "Enable code coverage instrumentation" OFF)

if(ENABLE_COVERAGE)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        add_compile_options(--coverage)
        add_link_options(--coverage)
    else()
        message(FATAL_ERROR "Coverage configuration currently supports GCC only")
    endif()
endif()

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(plugins)
add_subdirectory(utils)

install(TARGETS DeviceMonitorPlatform
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

#qt_generate_deploy_app_script(
#    TARGET DeviceMonitorPlatform
#    OUTPUT_SCRIPT deploy_script
#    NO_UNSUPPORTED_PLATFORM_ERROR
#)

#install(SCRIPT ${deploy_script})