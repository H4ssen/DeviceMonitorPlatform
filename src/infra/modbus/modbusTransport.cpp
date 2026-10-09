#include "modbusTransport.h"
#include <QModbusRtuSerialClient>
#include <iostream>
#include <QString>
#include <QVariant>
#include <QModbusDataUnit>
#include <QModbusReply>
#include "qtUtils.h"

ModbusTransport::ModbusTransport(const TransportConfig& config) {

    modbus_.setConnectionParameter(QModbusDevice::SerialPortNameParameter,QString::fromStdString(config.serial.port));
    modbus_.setConnectionParameter(QModbusDevice::SerialBaudRateParameter,QtUtils::toQtBaudRate(config.serial.baudRate));
    modbus_.setConnectionParameter(QModbusDevice::SerialParityParameter,QtUtils::toQtParity(config.serial.parity));
    modbus_.setConnectionParameter(QModbusDevice::SerialStopBitsParameter,QtUtils::toQtStopBits(config.serial.stopBits));

}

bool ModbusTransport::connect() {
    if (!modbus_.connectDevice()) {
        qWarning()<<" Failed to connect to mdobusClient "<< modbus_.errorString();
        return false;
    }
    qInfo()<<" modbusClient Connected Succeffully";
    return true;
}

bool ModbusTransport::disconnect() {
    
    if (modbus_.state() == QModbusDevice::UnconnectedState) {
        return true;
    }

    modbus_.disconnectDevice();

    if (modbus_.state() == QModbusDevice::UnconnectedState) {
        qInfo()<<" modbusClient Disconnected Succeffully";
        return true;
    }

    qWarning()<<" modbusClient unable to disconnect " <<modbus_.errorString();
    return false;
}

void ModbusTransport::pollDevice() {
    QModbusDataUnit readUnit(QModbusDataUnit::HoldingRegisters,//type of access
        0,//starting register
        4);//number of units
    if (QModbusReply* reply =  modbus_.sendReadRequest(readUnit,1/*server ID*/)) {
        if (!reply->isFinished()) {
            if (reply->error() == QModbusDevice::NoError) {
                const QModbusDataUnit unit = reply->result();
                for (int i =0; i < unit.valueCount(); i++) {
                    output_+= i + " = " + unit.value(i);
                }
                emit readyRead();
            } else {
                //error
            } 
            reply->deleteLater();
        } else {
            reply->deleteLater();
        }
    } else {
        //error
    }
}