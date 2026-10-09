#include "tcpTransport.h"
#include "transportConfig.h"
#include <QString>


TCPTransport::TCPTransport(const TransportConfig& config) {
    host_ = QString::fromStdString(config.tcp.host);
    port_ = config.tcp.port;
}

bool TCPTransport::connect() {
    socket_.connectToHost(host_,port_);
    if(! socket_.waitForConnected(3000)) {
        qWarning()<< "TCP connection failed : "<<socket_.errorString();
        return false;
    }
    qInfo()<<" succeffully connected to "<<host_<<":"<<port_;
    return true;
}

bool TCPTransport::disconnect() {
    if (socket_.state() == QAbstractSocket::UnconnectedState) {
        return true;
    }

    socket_.disconnectFromHost();

    if (socket_.waitForDisconnected(3000)) {
        qInfo()<<" TCP disconnected successfully ";
        return true;
    }
   
    qWarning() <<" TCP unable to disconnect : "<<socket_.errorString();
    return false;

}