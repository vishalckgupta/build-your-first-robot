/*
 * Build Your First Robot — Obstacle Avoidance Mode
 * Arduino Uno + L298N + two forward-facing IR sensors
 *
 * Motor direction: right D2/D3, left D4/D5
 * Motor PWM:       right D9,    left D10
 * Obstacle sensors:right D8,    left D12
 *
 * Sensor behavior in this sketch:
 * LOW/LOW   -> stop
 * HIGH/LOW  -> right (left/right sensor order)
 * LOW/HIGH  -> left
 * HIGH/HIGH -> forward
 *
 * Turning routines reverse first, then turn for a fixed duration.
 * Note: This is a separate sketch, not simultaneous obstacle + line control.
 * The control logic and numeric values below are preserved from the original.
 */

int mr1=2;  //motor right 1
int mr2=3;  //motor right 2
int ml1=4;  //motor left 1
int ml2=5;  //motor left 2
int sr=8;   //sensor right
int sl=12;  //sensor left
int svr=0;  // sensor state variable right
int svl=0;  // sensor state variable left
int led=13; // LED for visual output
int enr=9;  // Speed control pin right
int enl=10; // Speed control pin left
int vspeed=100;    // Straight line speed
int tspeed=100;    // Turn speed
int tdelay=2000;     // Turn delay
int rdelay=700;   // reverse delay

void   setup()
{
 pinMode(mr1, OUTPUT);
 pinMode(mr2, OUTPUT);
 pinMode(ml1, OUTPUT);
 pinMode(ml2, OUTPUT);
 pinMode(led, OUTPUT);
 pinMode(sr, INPUT);
 pinMode(sl, INPUT);
   
 delay(5000);
}

void loop()
{
  svr=digitalRead(sr);
  svl=digitalRead(sl);
   
  if (svl == LOW && svr == LOW)
  {
    stop();
    //forward();   // No line detected, move forward
  }

  if (svl == HIGH && svr == LOW)
  {
    right();
    //left();      // Line detected by Left sensor, turn left
  }
 
  if (svl == LOW && svr == HIGH)
  { 
    left();
    //right();     // Line detected by Right sensor, turn right
  }
  
  if (svl == HIGH && svr == HIGH)
  {
    forward();
    //stop();      // Both sensors detect line. stop
  }
}

void forward()
{
  digitalWrite(mr1, HIGH);
  digitalWrite(mr2, LOW);
  digitalWrite(ml1, HIGH);
  digitalWrite(ml2, LOW);
  analogWrite(enr, vspeed);
  analogWrite(enl, vspeed);
} 

void reverse()
{
  digitalWrite(mr1, LOW);
  digitalWrite(mr2, HIGH);
  digitalWrite(ml1, LOW);
  digitalWrite(ml2, HIGH);
  analogWrite(enr, vspeed);
  analogWrite(enl, vspeed);
}

void right()
{
  stop();
  reverse();
  delay(rdelay);
  digitalWrite(mr1, LOW);
  digitalWrite(mr2, LOW);
  digitalWrite(ml1, HIGH);
  digitalWrite(ml2, LOW);
  analogWrite(enr, tspeed);
  analogWrite(enl, tspeed);
  delay(tdelay);
} 

void left()
{
  stop();
  reverse();
  delay(rdelay);
  digitalWrite(mr1, HIGH);
  digitalWrite(mr2, LOW);
  digitalWrite(ml1, LOW);
  digitalWrite(ml2, LOW);
  analogWrite(enr, tspeed);
  analogWrite(enl, tspeed);
  delay(tdelay);
}  

void stop()
{
  analogWrite(enr, 0);
  analogWrite(enl, 0);
}
