#include "transportFactory.h"


void TransportFactory::registerType(const std::string& typeName, Creator creator) {
    creators_[typeName] = std::move(creator);
}

std::unique_ptr<IDeviceTransport> TransportFactory::create(const std::string& typeName, const TransportConfig& config) {
    auto it = creators_.find(typeName);
    if (it == creators_.end()) return nullptr;
    return it->second(config);
}