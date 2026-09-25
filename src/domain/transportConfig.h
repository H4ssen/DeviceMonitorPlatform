#pragma once
#include <cstdint>
#include <string>

class TransportConfig {

};

class SerialConfig {
    std::string port;
    uint32_t baudRate{115200};
    uint8_t dataBits{8};
    uint8_t stopBits{1};

};

class tcpConfig {
    std::string host;
    uint16_t port;
};

