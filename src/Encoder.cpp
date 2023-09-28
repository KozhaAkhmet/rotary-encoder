#include "Encoder.h"

Encoder::Encoder(int out_pin, int total_amount) {
    this->out_pin = out_pin;
    this->total_amount = total_amount;
}

void Encoder::Setup() {
    pinMode(this->out_pin, INPUT);
}

// This function begins to count LOW to HIGH switches. Also, function will take reminder from count value by total_amount, so the count value will be resetted after reaching the total_amount. This includes negative values.
// Use this function in loop.
void Encoder::Count() {
    if (digitalRead(this->out_pin) == 0) {
        state = true;
    } else if (digitalRead(this->out_pin == 1 && state == true) {
        this->counter = this->counter >= this->total_amount ||
                            this->counter <= -this->total_amount ?
                            (this->counter % this->total_amount) + this->dir :
                            this->counter + this->dir;
        state = false;
    }
}

//You can set the direction, so the count value will be added or subtracted by given parameter. For example, passing 1 or -1.
void Encoder::setDir(int dir){
    this->dir = dir;
}

//Get the counter value.
int Encoder::getCounter() {
    return this->counter;
}