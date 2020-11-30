/* 
Objet : Mesure temperature et hygrometrie avec un capteur dht22 
Nom : phmo_temp_humi_dht22.ino 
Infos sketch : 
- Créé le 10 jan 2017 
*/

#include "DHT.h"    // Librairie des capteurs DHT
#define DHTPIN 7    // Fixer la patte pin sur laquelle est branchée le DHT
#define DHTTYPE DHT22     

DHT dht(DHTPIN, DHTTYPE); // Instanciation objet dht

void setup() { 
  Serial.begin(9600); // ouverture connexion serie 
  Serial.println("Tests DHT22 ----------------------"); 
  dht.begin(); 
  } 
  
void loop() {
  float h = dht.readHumidity();   // lecture humidité et affectation a une variable de type float 
  float t = dht.readTemperature(); // lecture température et affectation a une variable de type float 
  // test si retour sonde dht2 à ok ou pas ... 
  if (isnan(t) || isnan(h)) { 
    Serial.println("Erreur de lecture sonde dht22");
    } 
   else { 
    //affichage des donnees sur la console serie 
    Serial.print("Humidite : " ); 
    Serial.print(h); Serial.print( " %\t "); 
    Serial.print(" Temperature : " ); 
    Serial.print(t); 
    Serial.println(" C "); 
    delay(1000); // attente de 1 seconde avant de refaire une mesure } }
   }
}
