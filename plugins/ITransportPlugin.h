#pragma once
#include <memory>


class ITransportPlugin {

    public:

    virtual ~ITransportPlugin() = default;

    virtual QString typeName() = 0;

    virtual std::unique_ptr<IDeviceTransport>

};