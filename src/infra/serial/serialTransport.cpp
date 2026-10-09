#include "transportConfig.h"
#include "serialTransport.h"
#include "qtUtils.h"
#include <QSerialPort>
#include <QDebug>
#include <iostream>

SerialTransport::SerialTransport(const TransportConfig& config) {

    serial_.setPortName(QString::fromStdString(config.serial.port));
    serial_.setBaudRate(QtUtils::toQtBaudRate(config.serial.baudRate));
    serial_.setParity(QtUtils::toQtParity(config.serial.parity));
    serial_.setStopBits(QtUtils::toQtStopBits(config.serial.stopBits));
    serial_.setFlowControl(QSerialPort::NoFlowControl);
}

bool 
SerialTransport::connect() {
    if (!serial_.open(QIODevice::ReadWrite)) {
        qWarning()<<" Failed to open serial port: "<<serial_.errorString();
        return false;
    }
    return true;
}

bool 
SerialTransport::disconnect() {
    
}