#ifndef SERIALSERVICE_H
#define SERIALSERVICE_H

#include <QObject>
#include <QByteArray>
#include <QString>
#include <QTimer>
//#include <QHostAddress>

#include "posix_qextserialport.h"
#define READTIME 1000

class SerialService : public QObject
{
    Q_OBJECT
public:
    explicit SerialService(QObject *parent = 0);
    int writeToSerial(const QByteArray &byte);
    Posix_QextSerialPort *my_com;
    bool openCom();
    bool closeCom();
    void releaseSerial();
    QTimer* getTimer();
    int getComState();
    int com_state;
    QTimer *read_timer;
//    QHostAddress *serverIP;
signals:
    void receiveMsgFromSerial(QByteArray);
public slots:
    void readFromSerial();
private:


};

#endif // SERIALSERVICE_H
