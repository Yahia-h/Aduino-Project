
#include <Servo.h>
Servo servo1;
int mode=1;
int count=0;
int in=0;
int out=0;
int buzzer=2;
int button=4;
void setup()
{
pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(button, INPUT);
Serial.begin(9600);
servo1.attach(3);
}void loop()
{

if(mode==2){
  delay(2000);
in =map((analogRead(A0)), 0, 1023, 0, 100);
out =map((analogRead(A1)), 0, 1023, 0, 100);
Serial.print("In:");
Serial.println(in);
Serial.print("Out:");
Serial.println(out);
Serial.println(count);
if(count>=5){
digitalWrite(buzzer, HIGH);
if (out<=30)
{
servo1.write(90);
count--;
}
else
{
servo1.write(0);
}
}else
{
digitalWrite(buzzer, LOW);
if (in<=30)
{
servo1.write(90);
count++;
delay(4000);
}
else{servo1.write(0);};
if (out<=30)
{
servo1.write(90);
count--;
delay(4000);
}else{servo1.write(0);};
};
}else{
if(mode==1){
servo1.write(0);
if(digitalRead(button)==LOW){
mode=2;

}
}
}
}
