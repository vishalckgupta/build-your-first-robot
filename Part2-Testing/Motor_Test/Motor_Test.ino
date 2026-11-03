/*
 * Project : Build Your First Robot
 * Program : DC Motor Testing with L298N
 * Board   : Arduino Uno
 *
 * Tests a DC motor by ramping its speed up and down,
 * first in one direction and then in the other.
 *
 * Connections:
 *   Arduino D7 -> L298N IN1
 *   Arduino D8 -> L298N IN2
 *   Arduino D9 -> L298N ENA (PWM)
 *   Motor      -> L298N OUT1 / OUT2
 *   Arduino GND and L298N GND must be connected together.
 *   Use a suitable external supply for the motor driver.
 *   Remove the ENA jumper if fitted so D9 can control speed.
 */

const int MOTOR_IN1 = 7;
const int MOTOR_IN2 = 8;
const int MOTOR_ENA = 9;

// Gradually accelerate, hold speed, decelerate, and pause.
void fast_slow() {
  // Ramp PWM from 0 to 255 in increments of 5.
  for (int speed = 0; speed <= 255; speed += 5) {
    analogWrite(MOTOR_ENA, speed);
    delay(50);
  }

  // Run at full speed for 3 seconds.
  delay(3000);

  // Ramp PWM back down to 0.
  for (int speed = 255; speed >= 0; speed -= 5) {
    analogWrite(MOTOR_ENA, speed);
    delay(50);
  }

  // Remain stopped for 3 seconds.
  delay(3000);
}

void setup() {
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(MOTOR_ENA, OUTPUT);

  // Begin with the motor stopped.
  analogWrite(MOTOR_ENA, 0);
}

void loop() {
  // Forward rotation.
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
  fast_slow();

  // Reverse rotation.
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, HIGH);
  fast_slow();

  // Additional pause before repeating the sequence.
  delay(3000);
}
