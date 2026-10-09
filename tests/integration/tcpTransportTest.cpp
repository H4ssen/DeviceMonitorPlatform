#include <QtTest/QtTest>
#include "transportConfig.h"
#include "tcpTransport.h"
#include <QTcpServer>

class TCPTransportIntegrationTest : public QObject {

    Q_OBJECT

    private slots:
        void failsForInvalidHost();
        void successfulConnection();

};


void
TCPTransportIntegrationTest::failsForInvalidHost() {

    //arrange
    TransportConfig config;
    config.tcp.host = "dummy";
    config.tcp.port = 8080;

    //act
    TCPTransport tcp(config);

    //assert
    QVERIFY(!tcp.connect());

}

void
TCPTransportIntegrationTest::successfulConnection() {

    //arrange
    QTcpServer server;
    QVERIFY(server.listen(QHostAddress::LocalHost,0));

    TransportConfig config;
    config.tcp.host = "127.0.0.1";
    config.tcp.port = server.serverPort();

    //act
    TCPTransport tcp(config);
    //assert
    QVERIFY(tcp.connect());

}

QTEST_MAIN(TCPTransportIntegrationTest);
#include "tcpTransportTest.moc"
