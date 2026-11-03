/*
 * Project : Build Your First Robot
 * Sketch  : IR Sensor Test
 * Board   : Arduino Uno
 *
 * Connections:
 *   IR sensor VCC -> Arduino 5V
 *   IR sensor GND -> Arduino GND
 *   IR sensor OUT -> Arduino digital pin 7
 *
 * The built-in LED (digital pin 13 on Uno) mirrors the
 * LOW state of the sensor output.
 *
 * Note: Many IR obstacle sensors are active-LOW. Check
 * your module's behavior before interpreting detection.
 */

const int IR_SENSOR_PIN = 7;
const int LED_PIN = LED_BUILTIN;

void setup() {
  Serial.begin(115200);
  Serial.println("IR Sensor Test Started");

  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Read the sensor's digital output.
  int sensorStatus = digitalRead(IR_SENSOR_PIN);

  if (sensorStatus == HIGH) {
    digitalWrite(LED_PIN, LOW);
    Serial.println("Sensor output: HIGH");
  } else {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Sensor output: LOW");
  }

  // Avoid flooding the Serial Monitor.
  delay(200);
}
