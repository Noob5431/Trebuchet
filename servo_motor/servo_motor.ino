#include <Servo.h>
#define servo_pin 2
#define button 7
#define trig 8
#define echo 9

Servo servo;

void setup() 
{
  Serial.begin(9600);
  servo.attach(servo_pin);
  pinMode(button, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  servo.write(0);
}

int angle1 = 0,angle2 = 120;
bool is1st = true;
void loop() 
{
  /*
  if(digitalRead(button))
  {
    if(is1st)
      {servo.write(angle1);
      is1st = false;
      }
    else {
      servo.write(angle2);
      is1st = true;
    }
    Serial.println("ceva ");
    delay(1000);
  }
  */
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);

  long duration = pulseInLong(echo, HIGH, 20000);

  long cm = duration/29/2;

  int activateThreshold = 1;

  Serial.println(cm);
  if(cm<=activateThreshold)
  {
    servo.write(angle2);

  }
  else if(digitalRead(button))
  {
    servo.write(angle1);
  }
}
