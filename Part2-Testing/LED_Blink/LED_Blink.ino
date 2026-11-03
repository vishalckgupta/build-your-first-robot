/*
 * Project : Build Your First Robot
 * Program : LED Blink Test
 * Board   : Arduino Uno
 *
 * Description:
 * Blinks the Arduino's built-in LED at one-second intervals.
 *
 * Concepts:
 * - setup() runs once; loop() repeats continuously.
 * - pinMode() configures a pin as an output.
 * - digitalWrite() switches the LED on and off.
 * - delay() pauses execution for milliseconds.
 *
 * Hardware:
 * Arduino Uno built-in LED (digital pin 13).
 * No external components are required.
 */

void setup() {
  // Set the built-in LED pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Turn the LED on and wait one second.
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);

  // Turn the LED off and wait one second.
  digitalWrite(LED_BUILTIN, LOW);
  delay(5000);
}
