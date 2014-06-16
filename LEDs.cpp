/*
 * FILE:    LEDs.cpp
 * PROGRAM: rover
 * PURPOSE: controls for LED status lights hooked up to a 74HC590, wiring not provided
 * AUTHOR:  Geoffrey Card
 * DATE:    2014-06-09
 * NOTES:
 */

#include "LEDs.h"

LEDs::LEDs(int clk_pin, int rs_pin)
{
    // initalize values
    _rs_pin = rs_pin;
    _clk_pin = clk_pin;
    _count = 0;
}

void LEDs::init(void)
{
    // setup pins
    pinMode(_rs_pin, OUTPUT);
    pinMode(_clk_pin, OUTPUT);

    // initial conditions
    digitalWrite(_rs_pin, HIGH);
    digitalWrite(_clk_pin, LOW);

    // ensure zeroed
    reset();
}

LEDs::~LEDs(void)
{
    reset();
}

int LEDs::get(void)
{
    return _count;
}

void LEDs::set(int count)
{
    // reset and count up
    reset();

    if (0 < count && count < 256) {
        for (int i = 0; i < count; i++) {
            increment();
        }
    }
    _count = count;
}

void LEDs::reset(void)
{
    // rs  -|_____|-
    // clk ___|-|___
    digitalWrite(_rs_pin, LOW);
    delay(COUNTER_DELAY);
    digitalWrite(_clk_pin, HIGH);
    delay(COUNTER_DELAY);
    digitalWrite(_clk_pin, LOW);
    delay(COUNTER_DELAY);
    digitalWrite(_rs_pin, HIGH);
    delay(COUNTER_DELAY);
    _count = 0;
}

void LEDs::increment(void)
{
    // rs  -----
    // clk _|-|_
    digitalWrite(_clk_pin, HIGH);
    delay(COUNTER_DELAY);
    digitalWrite(_clk_pin, LOW);
    delay(COUNTER_DELAY);
    _count++;
}

void LEDs::decrement(void)
{
    // ...yeah, this is only an up counter
    // down counters cost extra
    set(_count-1);
}

void LEDs::test(void)
{
    for (int i = 0; i < 256; i++) {
        set(i);
        delay(TEST_DELAY);
    }
    reset();
}
