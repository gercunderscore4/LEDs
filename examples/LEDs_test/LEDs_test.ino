/*
 * FILE:    LEDs_test.cpp
 * PROGRAM: rover
 * PURPOSE: controls for LED status lights hooked up to a 74HC590
 * AUTHOR:  Geoffrey Card
 * DATE:    2014-06-09 -
 * NOTES:   find out if there's a delay required during and between pulses
 */

#include <LEDs.h>
/*
 * 74HC590 pins:
 * pin  1 -> LED 1
 * pin  2 -> LED 2
 * pin  3 -> LED 3
 * pin  4 -> LED 4
 * pin  5 -> LED 5
 * pin  6 -> LED 6
 * pin  7 -> LED 7
 * pin  8 -> GND
 * pin  9 -> VCC
 * pin 10 -> LED 0
 * pin 11 -> GND
 * pin 12 -> CLK pin 37
 * pin 13 -> GND
 * pin 14 -> CLK pin 37
 * pin 15 -> RS pin 35
 * pin 16 -> X
 * recommend 1k resistor from CLK to GND and RS to VCC
 * VCC = +5V (or +3.3V)
 * Connect LED pin to LED anode, cathode to 1k resistor to GND
 */
LEDs myleds(37, 35);

void setup() {
    myleds.init();
    myleds.test();
}

void loop() {
    myleds.increment();
    delay(300);
}
