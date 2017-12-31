#ifndef ENDDEVICE_H
#define ENDDEVICE_H

#include <QObject>

class EndDevice : public QObject
{
    Q_OBJECT
public:
    explicit EndDevice(QObject *parent = 0);
    void setState(int);
    int getState();
protected:
    int state;

signals:

public slots:
};

#endif // ENDDEVICE_H
