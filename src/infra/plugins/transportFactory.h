#pragma once
#include <unordered_map>
#include <functional>
#include <string>

#include <memory>
#include "IDeviceTransport.h"
#include "transportConfig.h"




class TransportFactory {

    public:
        using Creator = std::function<std::unique_ptr<IDeviceTransport>(const TransportConfig& config)>;

        void registerType(const std::string& typeName, Creator creator);
        std::unique_ptr<IDeviceTransport> create(const std::string& typeName, const TransportConfig& config);

    private:

        std::unordered_map<std::string,Creator> creators_;
};