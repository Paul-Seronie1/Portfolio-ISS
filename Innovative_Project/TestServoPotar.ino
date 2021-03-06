/*
 Controler la position d'un servomoteur à l'aide d'un potentiomètre
 Traduction en français, ajout de variables de configuration
 Code original de BARRAGAN <http://barraganstudio.com>
 et Scott Fitzgerald http://www.arduino.cc/en/Tutorial/Knob
 
 www.projetsdiy.fr - 19/02/2016
 public domain

*/

#include <ESP32Servo.h>


Servo myservo;      // création de l'objet myservo
Servo myservo2;      // création de l'objet myservo

int potpin = 35; // Entrée analogique sur lequel est connecté le potentiomètre si vous utilisé un ESP32 remplacez le 0 par 35
int potpin2 = 34;
int val;            // Variable contenant la valeur courante du potentiomètre 
int val2;
int pin_servo = 4;       // Pin 6 sur lequel est branché le servo sur l'Arduino si vous utilisez un ESP32 ou un ESP8266 remplacez le 6 par 4
int pin_servo2 = 2;
bool angle_actuel = true;// Envoi sur le port série la position courante du servomoteur


void setup() {
  Serial.begin(9600);       // Ouvre le port série                   
  while(!Serial){;}     
  myservo.attach(pin_servo);// attache le servo au pin spécifié sur l'objet myservo
  myservo2.attach(pin_servo2);// attache le servo au pin spécifié sur l'objet myservo

}

void loop() {
  val = analogRead(potpin);            // Lit la valeur actuelle du potentiomètre (valeur comprise entre 0 et 1023)
  val2 = analogRead(potpin2);
  //val = map(val, 0, 1023, 0, 180);     // Mise à l'échelle pour renvoyer la position entre 0 et 180°
//Si vous utilisez un ESP32:
  val = map(val, 0, 4095, 0, 180);
  val2 = map(val2, 0, 4095, 0, 180); 
  myservo.write(val);                  // Déplace le servo à la position spécifiée
  myservo2.write(val2);                             
  if (angle_actuel) {
      Serial.print("Angle demande (1) : ");
      Serial.print(val);
      Serial.print(" | Position reelle (1) : ");
      Serial.println(myservo.read());
      Serial.print("Angle demande (2) : ");
      Serial.print(val2);
      Serial.print(" | Position reelle (2) : ");
      Serial.println(myservo2.read());
      delay(200);
  } else {
    delay(30);                          // Attend 15ms
  }
}
