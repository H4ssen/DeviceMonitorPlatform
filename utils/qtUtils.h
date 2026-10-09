#pragma once
#include <QSerialPort>
#include "transportConfig.h"

namespace QtUtils {
    
    QSerialPort::BaudRate toQtBaudRate(int baudRate);
    QSerialPort::Parity toQtParity(Parity parity);
    QSerialPort::StopBits toQtStopBits(StopBits bits);

};