
#pragma once
#include <QObject>
#include <QTcpSocket>
#include "IDeviceTransport.h"
#include "transportConfig.h"


class TCPTransport : public QObject , public IDeviceTransport {
    Q_OBJECT

    public:
        explicit TCPTransport(const TransportConfig& config) ;
        bool connect() override;
        bool disconnect() override;

    private:
        QTcpSocket socket_;
        QString host_;
        int port_;

};