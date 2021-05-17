/*
 Nom : pm_attiny_isp_chenillard.ino
 Description : Chenillard avec un ATTINY 85 programmé en ISP avec un Arduino UNO
 Creation : phmarduino le 11 12 2015
 Mise a jour : 
 */

#define VERT 0    // La led verte est sur la brohe 0 de l'ATTINY
#define ROUGE 3   // La led rouge est sur la brohe 3 de l'ATTINY
#define BLEU 2    // La led bleue est sur la brohe 2 de l'ATTINY
#define JAUNE 1   // La led jaune est sur la brohe 1 de l'ATTINY

// Initialisation en sortie des pattes et extinction des LEDs
void setup() {
  pinMode(VERT, OUTPUT);
  pinMode(ROUGE, OUTPUT);
  pinMode(BLEU, OUTPUT);
  pinMode(JAUNE, OUTPUT);
  digitalWrite(VERT, LOW); 
  digitalWrite(ROUGE, LOW); 
  digitalWrite(BLEU, LOW); 
  digitalWrite(JAUNE, LOW); 
}

// Boucle d allumage et extinction des LEDs en série                          
void loop() {
  digitalWrite(BLEU, HIGH);   // allumage led bleue
  delay(1000);                // attente une seconde
  digitalWrite(BLEU, LOW);    // extinction de la led bleue
  delay(1000);                // attente une seconde
  
  digitalWrite(JAUNE, HIGH);   
  delay(1000);              
  digitalWrite(JAUNE, LOW);    
  delay(1000);              
  
  digitalWrite(VERT, HIGH);   
  delay(1000);              
  digitalWrite(VERT, LOW);   
  delay(1000);              
  
  digitalWrite(ROUGE, HIGH);   
  delay(1000);              
  digitalWrite(ROUGE, LOW);    
  delay(1000);             
}
