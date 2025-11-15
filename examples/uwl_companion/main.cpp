#ifndef ARDUINO_NRF52840_PCA10059
#error "This firmware is not portable and only tested on the NRF52840 Dongle"
#endif

#include <Arduino.h>

// A configuration issue causes the preprocessor to select the wrong
// peripheral header in the Arduino framework. Among possible other
// issues, it causes GPIO_COUNT to be set to 1. Therefore, unless
// the configuration is worked around, any pin numbers intended
// to refer to pins in the second GPIO port will not work as expected.
static_assert(GPIO_COUNT == 2);

using logic_t = int;
using milliseconds = unsigned long;

namespace {
  // Quantity is in milliseconds.
  milliseconds g_last_toggled_at{};
  logic_t g_LED_logic_state{};

} // end anonymous namespace

void
setup()
{
  pinMode(LED_GREEN, OUTPUT);
  digitalWrite(LED_GREEN, HIGH);

  g_last_toggled_at = millis();
  // The LEDs on the nRF52840 Dongle are active low.
  g_LED_logic_state = HIGH;
}

void
loop()
{
  milliseconds const now{millis()};
  if (now - g_last_toggled_at > 1000) {
    g_LED_logic_state = 1ul - g_LED_logic_state;
    g_last_toggled_at = now;

    digitalWrite(LED_GREEN, g_LED_logic_state);
  }
}
