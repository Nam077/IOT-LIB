#include "Relay.h"

Relay::Relay(){
}

Relay::Relay(uint8_t pin) : pin(pin), state(false) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

void Relay::on() {
    digitalWrite(pin, HIGH);
    state = true;
}

void Relay::off() {
    digitalWrite(pin, LOW);
    state = false;
}

void Relay::toggle() {
    if (state) {
        off();
    } else {
        on();
    }
}

bool Relay::isOn() {
    return state;
}

bool Relay::isOff() {
    return !state;
}

