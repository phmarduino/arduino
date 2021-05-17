/*
  Nom : pm_attiny_isp_blink.ino
  Creation : PHMARDUINO, le 22/01/2020
  Mise a jour : 
  Description : Fait clignoter une LED sur un ATtiny85 branchée sur PB4 (broche 3)
 */
// Initialisations
void setup() {
  // Initialise digital pin ATtiny PB4 en sortie.
  pinMode(4, OUTPUT);
}
// Boucle infinie
void loop() {
  digitalWrite(4, HIGH);   // Allume la LED 
  delay(5000);             // Tempo
  digitalWrite(4, LOW);    // Eteint la LED
  delay(5000);             // Tempo
}
