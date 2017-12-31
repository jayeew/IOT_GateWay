#include "changepwm.h"

ChangePwm::ChangePwm()
{

}

QByteArray ChangePwm::RANGE("\x00\x01\x02\x03\x04\x05", 6);
QByteArray ChangePwm::MSG_PWM("\x40\x06\x01\x09\x00\x50", 6);
