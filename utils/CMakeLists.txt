add_library(QtUtils STATIC qtUtils.cpp)

target_include_directories(QtUtils PUBLIC 
                            ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(QtUtils PUBLIC
                      DeviceDomain
                      Qt::Core 
                      Qt::SerialPort)
