#ifndef RELAY_h
#define RELAY_h

#include "Arduino.h"

class Relay {
public:
    Relay(uint8_t pin);
    void on();
    void off();
    void toggle();
    bool isOn();
    bool isOff();
private:
    uint8_t pin;
    bool state;
};

#endif