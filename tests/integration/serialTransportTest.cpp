#include <QtTest/QtTest>
#include "transportConfig.h"
#include "serialTransport.h"
#include <iostream>


//virtual serial terminal 
#include <pty.h>
#include <unistd.h>


class SerialTransportIntegrationTest : public QObject {

    Q_OBJECT

    private slots:
        void failsForInvalidPort();
        void successfulConnection();
};


void
SerialTransportIntegrationTest::failsForInvalidPort() {
    //arrange
    TransportConfig config;
    config.serial.port = "dump";
    config.serial.baudRate = 115200;
    config.serial.dataBits = 8;
    config.serial.parity = Parity::None;
    config.serial.stopBits = StopBits::One;

    //act
    SerialTransport serial(config);

    //assert 
    QVERIFY(!serial.connect());
}

void 
SerialTransportIntegrationTest::successfulConnection() {

    //arrange
    int slaveFD;
    int masterFD;
    char slaveName[256]{};

    QVERIFY(openpty(
        &masterFD,
        &slaveFD,
        slaveName,
        nullptr,
        nullptr) != -1);
    
    std::cout<<" pty port "<<slaveName<<" created successfully "<<std::endl;
    TransportConfig config;
    config.serial.port = slaveName;
    config.serial.baudRate = 115200;
    config.serial.dataBits = 8;
    config.serial.parity = Parity::Even;
    config.serial.stopBits = StopBits::One;

    //act
    SerialTransport serial(config);

    //assert
    QVERIFY(serial.connect());

    //clean
    close(masterFD);
    close(slaveFD);

}


QTEST_MAIN(SerialTransportIntegrationTest)
#include "serialTransportTest.moc"