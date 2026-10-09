#serial transport tests
add_executable(serialTransportIntegrationTest 
                    ${CMAKE_CURRENT_SOURCE_DIR}/integration/serialTransportTest.cpp)

target_link_libraries(serialTransportIntegrationTest PRIVATE
                        SerialTransport
                        DeviceDomain
                        QtUtils
                        util
                        Qt::Test
                        Qt::Core)

add_test(NAME serialTransportIntegrationTest
         COMMAND serialTransportIntegrationTest)

set_tests_properties(serialTransportIntegrationTest 
                    PROPERTIES 
                        LABELS "integration"
)

#tcp transport tests

add_executable(tcpTransportIntegrationTest 
                ${CMAKE_CURRENT_SOURCE_DIR}/integration/tcpTransportTest.cpp)

target_link_libraries(tcpTransportIntegrationTest
                        PRIVATE 
                        DeviceDomain
                        tcpTransport
                        Qt::Test
                        Qt::Core
                    )

add_test(NAME tcpTransportIntegrationTest 
         COMMAND tcpTransportIntegrationTest)

set_tests_properties(tcpTransportIntegrationTest
          PROPERTIES 
            LABELS "integration")

#modbus transport test

add_executable(modbusTransportIntegrationTest 
                ${CMAKE_CURRENT_SOURCE_DIR}/integration/modbusTransportTest.cpp)
                
target_link_libraries(modbusTransportIntegrationTest
                PRIVATE 
                DeviceDomain
                modbusTransport
                Qt::Test 
                Qt::Core )
                
add_test(NAME modbusTransportIntegrationTest 
        COMMAND modbusTransportIntegrationTest)
        
set_tests_properties(modbusTransportIntegrationTest 
            PROPERTIES 
             LABELS "integration")

#support

add_executable(modbusSim ${CMAKE_CURRENT_SOURCE_DIR}/support/modbusRtuSim.c)
