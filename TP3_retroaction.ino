/* Utilisation du capteur Ultrason HC-SR04 */
#include <Servo.h>
#include <Chrono.h>

Servo servo;
SuperChrono chrono;

// définition des broches utilisées
int angle = 0;
int trig = 12;
int echo = 11;
long lecture_echo;
long cm;
int threshold = 8;
int priereManequin = false;

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
  servo.attach(9);
}

void loop()
{
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  lecture_echo = pulseIn(echo, HIGH);
  cm = lecture_echo / 58;
  Serial.println(cm);
  delay(20);
}

void prier(int distance) {
  
}

