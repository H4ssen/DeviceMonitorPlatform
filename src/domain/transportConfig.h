#pragma once
#include <cstdint>
#include <string>

enum class Parity {
    None,
    Even,
    Odd
};

enum class StopBits {
    One,
    Two
};


struct TransportConfig {
    struct serial {
        std::string port;
        int baudRate{115200};
        int dataBits{8};
        Parity parity{Parity::None};
        StopBits stopBits{StopBits::One};
    };

    struct tcp {
        std::string host;
        int port;
    };

    serial serial;
    tcp tcp;
    
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

