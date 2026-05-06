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

/**
 * This is a variant for the nRF52840 Dongle (pca10059) from
 * Nordic Semiconductor, with default peripheral interfaces appropriate
 * for the 2025-2026 off-grid mesh CPE capstone project at UW-LaCrosse.
 *
 * The variant defines the following peripheral interfaces:
 *
 * - Serial (1)
 * - SPI (2)
 * - QSPI (1)
 * - Wire (1)
 */

#ifndef _VARIANT_PCA10059_
#define _VARIANT_PCA10059_

#include "WVariant.h"

// Master clock frequency
#define VARIANT_MCK       (64000000ul)

// Board uses 32khz crystal for LF
#define USE_LFXO

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

// Not all of the 48 pins on the nRF52840 MCU are exposed by the
// nRF52840 Dongle. All pins that are not exposed are mapped to
// Arduino pin 0xff.
#define PINS_COUNT           (48u)
#define NUM_DIGITAL_PINS     (48u)
#define NUM_ANALOG_INPUTS    (4u)

// PIN_LED1, PIN_LED2, and PIN_LED4 all correspond to LED2 in the
// datasheet, which is an RGB LED component. All four of these
// pins will be initially be configured as OUTPUT pins by default.
#define PIN_LED1             (6u)
#define PIN_LED2             (8u)
#define PIN_LED3             (41u)
#define PIN_LED4             (12u)

#define LED_BUILTIN          PIN_LED1
#define LED_CONN             PIN_LED4

#define LED_RED              PIN_LED2
#define LED_GREEN            PIN_LED3
#define LED_BLUE             PIN_LED4

// All LEDs on the nRF52840 Dongle are active low (see the datasheet).
#define LED_STATE_ON         0

// This pin may be used to read the state of the on-chip push button.
//
// To use the button, configure this pin as an input with an internal
// pull-up resistor. It will be configured this way by default.
#define PIN_BUTTON1        (38u)

// These four pins may be used as analog input (AIN) pins.
//
// The nRF52840 MCU has eight analog input (AIN) pins, but
// the nRF52840 Dongle only exposes these four.
#define PIN_A0               (2u)
#define PIN_A1               (4u)
#define PIN_A2               (29u)
#define PIN_A3               (31u)

#define ADC_RESOLUTION       (14)

static const uint8_t A1  = PIN_A1 ;
static const uint8_t A2  = PIN_A2 ;
static const uint8_t A3  = PIN_A3 ;

// Unless CONFIG_NFCT_PINS_AS_GPIOS is defined, these pins will not be
// available to use as GPIO pins.
#define PIN_NFC1           (9u)
#define PIN_NFC2           (10u)

#define PIN_SERIAL1_RX      (45u)
#define PIN_SERIAL1_TX      (47u)

#define SPI_INTERFACES_COUNT 2

#define PIN_SPI_MISO         (33u)
#define PIN_SPI_MOSI         (34u)
#define PIN_SPI_SCK          (2u)

#define PIN_SPI1_MISO         (15u)
#define PIN_SPI1_MOSI         (17u)
#define PIN_SPI1_SCK          (20u)

#define PIN_QSPI_SCK         (31u)
#define PIN_QSPI_CS          (11u)
#define PIN_QSPI_IO0         (29u)
#define PIN_QSPI_IO1         (14u)
#define PIN_QSPI_IO2         (04u)
#define PIN_QSPI_IO3         (26u)

#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (36u)
#define PIN_WIRE_SCL         (39u)

#ifdef __cplusplus
}
#endif

#endif // _VARIANT_PCA10059_
