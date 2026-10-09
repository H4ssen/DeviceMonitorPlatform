#include <QtTest/QtTest>
#include <pty.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>




class ModbusRtuTransportTest : public QObject {

    Q_OBJECT

    private slots:
    
    void simulateConnection();

};


void 
ModbusRtuTransportTest::simulateConnection() {

    //arrange

    int slaveFD;
    int masterFD;
    char slaveName[256]{};

    QVERIFY(openpty(&masterFD,
        &slaveFD,
        slaveName,
        nullptr,
        nullptr
    ) != -1);

    pid_t pid = fork();

    QVERIFY(pid >= 0);
    if (pid == 0) {
        char fdString[16];
        snprintf(fdString, sizeof(fdString), "%d", masterFD);
        execl("./modbusSim",
                "modbusSim",
                fdString,
            nullptr);

        perror("execl");
        _exit(1);
    }

    int status = 0;
    QVERIFY(waitpid(pid, &status,0) != -1);

    QVERIFY(WIFEXITED(status));

    QCOMPARE(WEXITSTATUS(status),0);


    close(slaveFD);
    close(masterFD);

}

QTEST_MAIN(ModbusRtuTransportTest);
#include "modbusTransportTest.moc"