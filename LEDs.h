/*
 * FILE:    LEDs.h
 * PROGRAM: rover
 * PURPOSE: controls for LED status lights hooked up to a 74HC590
 * AUTHOR:  Geoffrey Card
 * DATE:    2014-06-09
 * NOTES:
 */

#ifndef LEDS_H_
#define LEDS_H_

#define COUNTER_DELAY 0 // ms // delay between state switches
#define TEST_DELAY 300  // ms // delay between numbers during test

#include <Arduino.h>

class LEDs {
private:
    int _clk_pin;   // maintain LOW, go HIGH then LOW for inc
    int _rs_pin;    // maintain HIGH, go LOW and inc clk for reset

    int _count; // there are 8 lights // not 4

public:
    LEDs (int clk_pin, int rs_pin);
    ~LEDs (void);

    void init (void);

    int get (void);
    void set (int count);
    void reset (void);

    void increment (void);
    void decrement (void);

    void test (void);
};

#endif //LEDS_H_
