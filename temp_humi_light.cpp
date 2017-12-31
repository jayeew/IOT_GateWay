#include "temp_humi_light.h"

Temp_Humi_Light::Temp_Humi_Light(){
    temperature = 0;
    humidity = 0;
    light = 0;
}
void Temp_Humi_Light::setValue(int temperature, int humidity, float light){
    this->temperature = temperature;
    this->humidity = humidity;
    this->light = light;
}
void Temp_Humi_Light::setValue(QByteArray &byte){

    temperature = (byte[5] << 8) + byte[6];
    humidity = (byte[7] << 8) + byte[8];
    light = (byte[9]*256 + (byte[10] >> 2)) * 3.3 / 8192;
    light /= 4;
    light = light * 913;
}
int Temp_Humi_Light::getTemp(){
    return temperature;
}
int Temp_Humi_Light::getHumi(){
    return humidity;
}
float Temp_Humi_Light::getLight(){
    return light;
}
