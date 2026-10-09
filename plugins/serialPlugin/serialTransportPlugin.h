#pragma once
#include <QObject>
#include <QString>
#include <memory>


#include "ITransportPlugin.h"
#include "serialTransport.h"
#include "transportConfig.h"

class SerialTransportPlugin :  public QObject , public ITransportPlugin {
        Q_OBJECT
        Q_PLUGIN_METADATA(IID ITransportPlugin_iid  )
        Q_INTERFACES(ITransportPlugin)

    public:
        QString typeName() override {return "serial";}
        std::unique_ptr<IDeviceTransport> create(const TransportConfig& config) override;
};