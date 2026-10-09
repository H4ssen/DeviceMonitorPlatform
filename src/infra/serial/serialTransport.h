#pragma once
#include "IDeviceTransport.h"
#include "transportConfig.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QObject>



class SerialTransport : public QObject , public IDeviceTransport {
    Q_OBJECT
    public:
        explicit SerialTransport(const TransportConfig& config);
        bool connect()  override;
        bool disconnect()  override;

    private:
        QSerialPort serial_;

};