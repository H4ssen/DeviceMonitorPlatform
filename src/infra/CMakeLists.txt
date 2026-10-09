add_library(PluginInfra STATIC 
            plugins/transportFactory.cpp)
        
target_include_directories(PluginInfra PRIVATE 
                            ${CMAKE_CURRENT_SOURCE_DIR}/plugins)

target_link_libraries(PluginInfra PRIVATE
                        PluginApi
                        DeviceDomain
                        Qt::Core)

#serial transport library
add_library(SerialTransport SHARED serial/serialTransport.cpp)

target_include_directories(SerialTransport PUBLIC 
                            ${CMAKE_CURRENT_SOURCE_DIR}/serial)

target_link_libraries(SerialTransport PUBLIC 
                      DeviceDomain
                      QtUtils
                      Qt::Core 
                      Qt::SerialPort)

#tcp transport library
add_library(tcpTransport SHARED tcp/tcpTransport.cpp)

target_include_directories(tcpTransport PUBLIC 
                            ${CMAKE_CURRENT_SOURCE_DIR}/tcp)

target_link_libraries(tcpTransport PUBLIC 
                      DeviceDomain
                      Qt::Core 
                      Qt::Network)

#modbus transport library
add_library(modbusTransport SHARED modbus/modbusTransport.cpp)

target_include_directories(modbusTransport PUBLIC 
                            ${CMAKE_CURRENT_SOURCE_DIR}/tcp)

target_link_libraries(modbusTransport PUBLIC 
                      DeviceDomain
                      QtUtils
                      Qt::Core 
                      Qt::SerialBus)