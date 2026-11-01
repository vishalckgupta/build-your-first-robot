/*
 * Build Your First Robot — Line Following Mode
 * Arduino Uno + L298N + two downward-facing IR sensors
 *
 * Motor direction: right D2/D3, left D4/D5
 * Motor PWM:       right D9,    left D10
 * Line sensors:    right D7,    left D6
 *
 * Sensor behavior in this sketch:
 * LOW/LOW   -> forward
 * HIGH/LOW  -> left  (left/right sensor order)
 * LOW/HIGH  -> right
 * HIGH/HIGH -> stop
 *
 * Note: Sensor polarity and motor direction depend on wiring and module setup.
 * The control logic and numeric values below are preserved from the original.
 */

int mr1=2;  //motor right 1
int mr2=3;  //motor right 2
int ml1=4;  //motor left 1
int ml2=5;  //motor left 2
int sr=7;   //sensor right
int sl=6;   //sensor left
int svr=0;  // sensor state variable right
int svl=0;  // sensor state variable left
int led=13; // LED for visual output
int enr=9;  // Speed control pin right
int enl=10; // Speed control pin left
int vspeed=50;    // Straight line speed
int tspeed=50;    // Turn speed
int tdelay=0;     // Turn delay

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
    forward();   // No line detected, move forward
  }

  if (svl == HIGH && svr == LOW)
  {
    left();      // Line detected by Left sensor, turn left
  }
 
  if (svl == LOW && svr == HIGH)
  { 
    right();     // Line detected by Right sensor, turn right
  }
  
  if (svl == HIGH && svr == HIGH)
  {
    stop();      // Both sensors detect line. stop
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

void backward()
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
