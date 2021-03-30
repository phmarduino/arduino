/*
  Skecth      : pm_BT_HC06_53_test_AT_11112020.ino
  Description : Test module Bluetooth HC06 avec des commandes AT
                NB : Pour le bon fonctionnement, le HC06 ne doit pas etre appairé a un téléphone, etc. 
  Auteur      : PHMARDUINO
  Création    : 11/11/2020
  Mise a jour : ...
  Cablage HC06 <---> Arduino UNO
   * VCC <–> +3.3V
   * GND <–> GND
   * TXD <–> Pin 10 (RX) 
   * RXD <–> Pin 11 (TX) via pont diviseur 5V vers 3.3V 
*/
//***********************************************/*  
#include <SoftwareSerial.h>  //Librairie Software Serial Port  
#define RX 10                //Pin 10 pour RX 
#define TX 11                //Pin 11 pour TX

// Creation objet serie pour le hc06
SoftwareSerial PhmHC06Serie(RX,TX);  

void setup()  
{  
  Serial.begin(9600);    
  Serial.println("Pret pour vos commandes AT ......");  
  PhmHC06Serie.begin(9600);  //Valeur par défaut pour le HC06
}  
void loop()  
{  
  //Lecture caracteres sur le PhmHC06Serie et affichage sur Terminal Serie 
  //et vice versa 
  if (PhmHC06Serie.available()) {  
    // Ce qui est recu depuis le HC06 est envoyé a la console
    Serial.write(PhmHC06Serie.read());  
  }  
  // Serial.write(blueToothSerial.read());  
  if (Serial.available()) {  
    // Ce qui est recu depuis la console est envoyé au HC06
    PhmHC06Serie.write(Serial.read());  
  }  
}  
