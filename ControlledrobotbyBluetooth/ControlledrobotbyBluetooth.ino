#define speedL 10
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define speedR 5
#define buzzer 3
char Reading;
char buzzerReading; 
void setup()
{ 
Serial.begin (9600);
for(int i=2 ; i<=10 ; i++)
{
pinMode(i, OUTPUT); 
} 
}
void forword()
{
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW); 
digitalWrite(IN3, HIGH); 
digitalWrite(IN4, LOW);
analogWrite(speedL,220);
analogWrite(speedR,220); 
}
void backword()
{
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH); 
digitalWrite(IN3, LOW); 
digitalWrite(IN4, HIGH);
analogWrite(speedL,220);
analogWrite(speedR,220); 
}
void left()
{
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW); 
digitalWrite(IN3, HIGH); 
digitalWrite(IN4, LOW); 
analogWrite(speedL,0);
analogWrite(speedR,220); 
}
void right()
{
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW); 
digitalWrite(IN3, LOW); 
digitalWrite(IN4, LOW);
analogWrite(speedL,220);
analogWrite(speedR,0); 
}
void stopp() {
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW); 
digitalWrite(IN3, LOW); 
digitalWrite(IN4, LOW);
analogWrite(speedL,0);
analogWrite(speedR,0); 
}
void forwordRight()
{
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW); 
digitalWrite(IN3, HIGH); 
digitalWrite(IN4, LOW);
analogWrite(speedL,220);
analogWrite(speedR,170); 
}
void forwordLeft()
{
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW); 
digitalWrite(IN3, HIGH); 
digitalWrite(IN4, LOW);
analogWrite(speedL,170);
analogWrite(speedR,220); 
}
void backwordLeft()
{
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH); 
digitalWrite(IN3, LOW); 
digitalWrite(IN4, HIGH);
analogWrite(speedL,220);
analogWrite(speedR,170); 
}
void backwordRight()
{
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH); 
digitalWrite(IN3, LOW); 
digitalWrite(IN4, HIGH);
analogWrite(speedL,170);
analogWrite(speedR,220); 
}
void backBuzzer(){
digitalWrite(2 , HIGH);tone(buzzer , 1000 , 500);delay(500) ; noTone(buzzer); delay(500);
}
void loop() {
  
if(Serial.available()>0){
  Reading=Serial.read();
   
  //  buzzerReading=Serial.read();
  //  if(buzzerReading == 'V'){
  //   digitalWrite(buzzer, HIGH);
  //   tone(buzzer , 1000  );
  //  }
  //  else if(buzzerReading == 'v'){
  //   noTone(buzzer);
  //  }
switch(Reading){
   case 'F': forword(); break;
   case 'B': backword();break;
   case 'R': right(); break;
   case 'L' : left(); break;
   case 'S' :stopp(); break;
   case 'I' : forwordRight(); break;
   case 'G' : forwordLeft(); break;
   case 'J' : backwordRight(); break;
   case 'H' : backwordLeft(); break;
   case 'V' : digitalWrite(buzzer, HIGH);break;
   case 'v' : digitalWrite(buzzer, LOW);break;
   case 'U' : digitalWrite(2 , HIGH);break;
   case 'u' : digitalWrite(2 , LOW);break;
  }
}
}
