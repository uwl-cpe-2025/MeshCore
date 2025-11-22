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

#ifndef _VARIANT_PCA10059_
#define _VARIANT_PCA10059_

/** Master clock frequency */
#define VARIANT_MCK       (64000000ul)

#define USE_LFXO      // Board uses 32khz crystal for LF
// define USE_LFRC    // Board uses RC for LF

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

// Not all of the 48 pins on the nRF52840 MCU are exposed by the
// nRF52840 Dongle. All pins that are not exposed are mapped to
// Arduino pin 0xff.
#define PINS_COUNT           (48)
#define NUM_DIGITAL_PINS     (48)
#define NUM_ANALOG_INPUTS    (4)
#define NUM_ANALOG_OUTPUTS   (0)

// PIN_LED1, PIN_LED2, and PIN_LED4 all correspond to LED2 in the
// datasheet, which is an RGB LED component.
#define PIN_LED1             (6)
#define PIN_LED2             (8)
#define PIN_LED3             (41)
#define PIN_LED4             (12)

#define LED_BUILTIN          PIN_LED2
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
#define PIN_BUTTON1        (38)

// These four pins may be used as analog input (AIN) pins.
//
// The nRF52840 MCU has eight analog input (AIN) pins, but
// the nRF52840 Dongle only exposes these four.
#define PIN_A0               (2)
#define PIN_A1               (4)
#define PIN_A2               (29)
#define PIN_A3               (31)

#define ADC_RESOLUTION       (14)

static const uint8_t A0  = PIN_A0 ;
static const uint8_t A1  = PIN_A1 ;
static const uint8_t A2  = PIN_A2 ;
static const uint8_t A3  = PIN_A3 ;

// Everything above here has been corrected and documented.
// Notes for future work:
//
//  PIN_SERIAL1_RX and PIN_SERIAL1_TX are used by UART
//  Same for PIN_SERIAL2_RX and PIN_SERIAL2_TX
//
//  We may want Serial1 for Adafruit logging. MeshCore also uses it for environment sensors.
//
//  PIN_WIRE_SDA and PIN_WIRE_SCL are used by Wire library for I2C
//
//  I don't think we need I2C. :)
//
//  PIN_SPI_XXX are used by the SPI library
//
//  I think we do need SPI.
//
//  It looks to me like the T-Echo uses a QSPI external flash. We need to look into that. :/
//
//  PIN_BUTTON1 is used for the backlight in the T-Echo platformio.ini, we might do the same. PIN_BUTTON2 isn't used that I could find yet.
//
//  The SX126X pins are necessary and will be used to communicate with the radio module. These are important.
//
//  Looks like we do not use PIN_SPI1_XXX.
//
//  We need to set P_LORA_XXX in the platform file.
//
//  We do need to define some DISP_XXX pins for the GxEPDDisplay.
//
//  We do need some GPS_XXX pins for the MeshCore sensors.


// Other pins
//#define PIN_AREF           (2)
//#define PIN_NFC1           (9)
//#define PIN_NFC2           (10)

//static const uint8_t AREF = PIN_AREF;

/*
 * Serial interfaces
 */

// Arduino Header D0, D1
// TODO tentative
#define PIN_SERIAL1_RX      (9)
#define PIN_SERIAL1_TX      (10)

/*
 * SPI Interfaces
 */
// TODO tentative
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MISO         (15)
#define PIN_SPI_MOSI         (17)
#define PIN_SPI_SCK          (20)

static const uint8_t SS   = 44 ;
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;

/*
 * Wire Interfaces
 */
// TODO tentative
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (22)
#define PIN_WIRE_SCL         (24)

// QSPI Pins
/*
#define PIN_QSPI_SCK         19
#define PIN_QSPI_CS          17
#define PIN_QSPI_IO0         20
#define PIN_QSPI_IO1         21
#define PIN_QSPI_IO2         22
#define PIN_QSPI_IO3         23
*/

// On-board QSPI Flash
/*
#define EXTERNAL_FLASH_DEVICES   MX25R6435F
#define EXTERNAL_FLASH_USE_QSPI
*/

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#endif // _VARIANT_PCA10059_
