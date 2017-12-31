#ifndef CHANGEPWM_H
#define CHANGEPWM_H

#include "enddevice.h"

class ChangePwm : public EndDevice
{
public:
    ChangePwm();
public:
    static QByteArray RANGE;
    static QByteArray MSG_PWM;
};

#endif // CHANGEPWM_H
