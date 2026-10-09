#pragma once
#include <memory>
#include <QString>

class TransportConfig;
class IDeviceTransport;

class ITransportPlugin {

    public:

    virtual ~ITransportPlugin() = default;

    virtual QString typeName() = 0;

    virtual std::unique_ptr<IDeviceTransport> create(const TransportConfig& config) = 0;

};

#define ITransportPlugin_iid "com.my_company.ITransportPlugin"
Q_DECLARE_INTERFACE(ITransportPlugin, ITransportPlugin_iid)