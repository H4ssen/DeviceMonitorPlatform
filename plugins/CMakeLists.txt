add_library(PluginApi INTERFACE )

target_include_directories(PluginApi 
                        INTERFACE
                        ${CMAKE_CURRENT_SOURCE_DIR}/plugin_api) 
                        
target_link_libraries(PluginApi INTERFACE 
                    DeviceDomain
                    Qt::Core)


add_library(SerialPlugin STATIC serialPlugin/serialTransportPlugin.cpp)

target_include_directories(SerialPlugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/serialPlugin)

target_link_libraries(SerialPlugin PUBLIC 
                     Qt::Core 
                     PluginApi
                     DeviceDomain
                     SerialTransport )