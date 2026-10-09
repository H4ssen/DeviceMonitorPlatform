#pragma once
#include "IDeviceTransport.h"
#include "transportConfig.h"
#include <QObject>
#include <QModbusRtuSerialClient>

class ModbusTransport : public QObject , public IDeviceTransport {
    Q_OBJECT

    public:
        explicit ModbusTransport(const TransportConfig& config);

        bool connect() override;
        bool disconnect() override;

    public slots:
        void pollDevice();

    signals:
        void readyRead();

    private:

        QModbusRtuSerialClient modbus_;
        QString output_;
};