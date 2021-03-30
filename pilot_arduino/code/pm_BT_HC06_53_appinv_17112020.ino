/*
  Skecth      : pm_BT_HC06_53_appinv_17112020.ino
  Description : Test module Bluetooth HC06 avec APP Inventor
  Auteur      : PHMARDUINO
  Création    : 17/11/2020
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

String cmd="";

#include "DHT.h"    // Librairie des capteurs DHT
#define DHTPIN 2    // Fixer la patte pin sur laquelle est branchée le DHT
#define DHTTYPE DHT22     

DHT dht(DHTPIN, DHTTYPE); 

void setup()  
{  
  pinMode(12, OUTPUT);
  Serial.begin(9600);    
  Serial.println("Pret ...");  
  PhmHC06Serie.begin(9600);  //Valeur par défaut pour le HC06
  dht.begin();
}  
void loop()  
{  
 //Lecture des données HC06
  while(PhmHC06Serie.available()>0){
    cmd+=(char)PhmHC06Serie.read();
  }

  //Traitement de la commande recue
  if(cmd!=""){
    Serial.print("Une commande a ete recue ....");
    Serial.println(cmd);
    // Commande LEDON pour allumage LED
    if(cmd=="LEDON"){
        Serial.println("Allumage LED");
        digitalWrite(12, HIGH);   
    }
    // Commande LEDOFF pour extinction LED
    if(cmd=="LEDOFF"){
        Serial.println("Extinction LED");
                digitalWrite(12, LOW); 
    }
    cmd=""; //Reset variable commande envoyée par Bluetooth
  }
    
  //Mesure et affichage console série temperature 
  float t = dht.readTemperature();
  Serial.print("temperature : ");
  Serial.println(t);

  //Envoi temperature au module BT HC06 pour le smartphone
  PhmHC06Serie.print(t);
  delay(1500); // delai de 1.5 secondes
}  
