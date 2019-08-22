/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  Google Plus https://goo.gl/gBnUdh
  Web https://www.proyecto-teos.com
*/

#include <Sim800l.h> //https://github.com/cristiansteib/Sim800l
#include <SoftwareSerial.h>

const char receiverNumberT[] = "5613494356", messageT[] = "Mensaje desde el modulo SIM800L numero ", optionalMessageT[] = ", by TEOS";
uint16_t countT = 0, messageDelayT = 5000;
String resultSerialT;

Sim800l Sim800l;

void setup() {
  Sim800l.begin();
  Serial.begin(9600);
}

void loop() {
  delay(messageDelayT);
  char stringMessageT[55];
  countT++;
  resultSerialT = "El mensaje se ha enviado a " + String(receiverNumberT) + " " + String(countT) + " veces.";
  Serial.println(resultSerialT);
  sprintf(stringMessageT, "%s%d%s", messageT, countT, optionalMessageT);
  Sim800l.sendSms(receiverNumberT, stringMessageT);
  memset(stringMessageT, 0, sizeof(stringMessageT));
}
