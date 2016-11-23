#include <Servo.h>
#include <NewPing.h>

#define MAX_DISTANCE 200
#define TRIGGER_PIN 12
#define ECHO_PIN 11

Servo servo;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


// définition des broches utilisées
int angle = 150;
int trig = 12;
int echo = 11;
long lecture_echo;
long cm;
int threshold = 4;
bool descenteMannequin = true;

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
  servo.attach(9);
  servo.write(angle);
}

void loop()
{
  unsigned int uS = sonar.ping_cm();
  Serial.println(uS);

  if(descenteMannequin == true) {
      if(uS <= threshold) {
        descenteMannequin = false;
      }
    servo.write(angle -= 1);
  }
  
  if (descenteMannequin == false) {
     if(angle >= 150) {
      descenteMannequin = true;
     }
    servo.write(angle += 1);
  }
  delay(20);
}

