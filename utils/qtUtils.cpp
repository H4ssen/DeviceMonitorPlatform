#include "qtUtils.h"
#include <QSerialPort>
#include "transportConfig.h"


namespace QtUtils {
    
    QSerialPort::BaudRate toQtBaudRate(int baudRate) {
        switch (baudRate)
        {
        case 115200:
            return QSerialPort::Baud115200;

        case 9600:
            return QSerialPort::Baud9600;
        
        default:
            throw std::invalid_argument("Unsupported baud rate");
        }
    }

    QSerialPort::Parity toQtParity(Parity parity) {
        switch (parity)
        {
        case Parity::None:
            return QSerialPort::NoParity;
            break;
        case Parity::Even:
            return QSerialPort::EvenParity;
            break;
        case Parity::Odd:
            return QSerialPort::OddParity;
        default:
            break;
        }
    }

    QSerialPort::StopBits toQtStopBits(StopBits bits) {
        switch (bits)
        {
        case StopBits::One:
            return QSerialPort::OneStop;
            break;
        case StopBits::Two:
            return QSerialPort::TwoStop;
            break;
        default:
            break;
        }
    }
};
