# SIM800L con Arduino
En esta entrada veremos cómo mandar mensajes de texto desde un módulo SIM800L con Arduino.

### Requisitos
- Tener el IDE de [Arduino](https://www.arduino.cc/en/Main/Software) (o el de tu preferencia) con la versión más actual
- Contar con las librería [Sim800l](https://github.com/cristiansteib/Sim800l)
- Tener el material para hacer el proyecto

### Código
**[Aqui](https://github.com/proyectoTEOS/SIM800L-con-Arduino/blob/master/SIM800L-con-Arduino.ino)** podrás obtener el link del código, también dejaremos
una vista previa aquí abajo.

```c++
/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  WEB https://www.proyecto-teos.com
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
```

### Diagrama
El siguiente esquemático muestra como se debe conectar todos los componentes con la placa.
![](https://github.com/proyectoTEOS/SIM800L-con-Arduino/blob/master/SIM800L-con-Arduino.jpg)
