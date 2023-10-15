#define motor_p 2
#define motor_n 3

void setup() 
{
  Serial.begin(9600);
  pinMode(motor_p, OUTPUT);
  pinMode(motor_n, OUTPUT);
}

void loop() 
{
  char input;

  if(Serial.available())
  {
    input = Serial.read();
  }

  digitalWrite(motor_p, LOW);
  digitalWrite(motor_n, HIGH);
  if(input=='w')
  {
    digitalWrite(motor_p, HIGH);
    digitalWrite(motor_n, LOW);
  }
  else if(input=='s')
  {
    digitalWrite(motor_p, LOW);
    digitalWrite(motor_n, HIGH);
  }
  else if(input=='x')
  {
    digitalWrite(motor_p, LOW);
    digitalWrite(motor_n, HIGH);
  }
}

