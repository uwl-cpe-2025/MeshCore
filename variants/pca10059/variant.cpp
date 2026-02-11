/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
  Copyright (c) 2016 Sandeep Mistry All right reserved.
  Copyright (c) 2018, Adafruit Industries (adafruit.com)

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "variant.h"

#include <Arduino.h>

// Pins 19, 21, 23, and 25 are connected to SW2 and should not be used.
// See the datasheet. Many other pins are not exposed on the dongle.
const uint32_t g_ADigitalPinMap[] =
{
  // P0
  0   , 1   , 2 , 0xff, 4   , 0xff, 6   , 0xff,
  8   , 9   , 10, 11  , 12  , 13  , 14  , 15  ,
  0xff, 17  , 18, 0xff, 20  , 0xff, 22  , 0xff,
  24  , 0xff, 26, 0xff, 0xff, 29  , 0xff, 31  ,

  // P1
  32  , 33, 34, 0xff, 36,   0xff,   38, 39,
  0xff, 41, 42, 43  , 0xff, 45  , 0xff, 47
};

void initVariant() {
  pinMode(PIN_BUTTON1, INPUT_PULLUP);

  pinMode(PIN_LED1, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);

  digitalWrite(PIN_LED1, HIGH);
  digitalWrite(LED_BLUE, HIGH);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_RED, HIGH);
}
