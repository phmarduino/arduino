
/*
  Skecth : pm_wemos_53_ntp_avec_date.ino
  Description : Recuperation date et heure sur internet via un serveur NTP
                en utilisant la bibliotheque de NTPClient Fabrice Weinberg
                et affichage heure et jour sur OLED SSD 1331
  WEB : https://phmarduino.wordpress.com
  GIT :                 
  Auteur : PHMARDUINO
  Création : 27 11 2018
  Mise a jour : 28 11 2018 - ajout affichage de la date
*/

// Appel des bibs
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#include <SPI.h>
#include <time.h>

// Declarations WIFI
const char* ssid = "le SSID (nom) de mon WIFI";
const char* password = "mon mot de passe WIFI";

// Variables de travail
unsigned long epoch = 0;
int nujour = 0; //numero jour de la semaine avec 0 pour dimanche
String jour = "mon jour"; // dimanche, lundi, etc.
String heure = "mon heure ..";
char buffer[80]; // Stockage de la date complete

// Declaration OLED SSD1331
#define sclk D5
#define mosi D7
#define cs   D8
#define rst  D3
#define dc   D1

// Declaration des couleurs
#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0
#define WHITE           0xFFFF

//Creation objet Adafruit_SSD1331 display 
Adafruit_SSD1331 display = Adafruit_SSD1331(cs, dc, mosi, sclk, rst);

//Creation objet WIFI UDP
WiFiUDP ntpUDP;

//Creation objet client NTP avec les parametres suivants :
// - pool de serveurs NTP
// - en option le décalage horaire en secondes, ici 3600 pour GMT+1, pour GMT+8 mettre 28800, etc.
// - en option l intervalle de mise à jour en millisecondes par défaut à 60 secondes
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 3600, 60000);

void setup(){
  // Demarrage liaison serie
  Serial.begin(115200);
  // Demarrage ecanr oled ssd1331
  display.begin();
  // Connection au reseau WIFI
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }
  // Demarrage client NTP
  timeClient.begin();
}

void loop() {
  // Recup heure puis affichage
  timeClient.update();
  epoch = timeClient.getEpochTime(); // Heure Unix
  nujour = timeClient.getDay();    // jour de la semaine
  heure = timeClient.getFormattedTime(); // heure

  // Calcul de la date en convertissant le temps UNIX epoch
  time_t timestamp = epoch;
  struct tm * pTime = localtime( & timestamp );
  strftime( buffer,80, "%d/%m/%Y", pTime );
  Serial.println(buffer);

  switch (nujour) { // on determine le jour
      case 0: 
        jour = "dimanche";
        break;
      case 1:
        jour = "lundi";
        break;
      case 2: 
        jour = "mardi";
        break;
      case 3: 
        jour = "mercredi";
        break;
      case 4: 
        jour = "jeudi";
        break;
      case 5: 
        jour = "vendredi";
        break;
       case 6: 
        jour = "samedi";
        break;
    }
  
  // Envoi des donnees recuperees sur la liaison serie
  Serial.print("Temps UNIX : ");
  Serial.print(epoch);
  Serial.print(" sec - jour : ");
  Serial.print(jour);
  Serial.print(" - heure : ");
  Serial.println(timeClient.getFormattedTime());

  // Affichage sur oled ssd1331
  display.fillScreen(BLACK);
  display.setTextSize(1);
  
  display.setCursor(0, 0);
  display.setTextColor(YELLOW);
  display.print(jour);

   display.setCursor(0, 10);
  display.setTextColor(YELLOW);
  display.print(buffer);

  display.drawFastHLine(0, 25, display.width() - 1, RED);

  display.setCursor(0, 30);
  display.setTextColor(WHITE);
  display.print(heure);

  display.drawFastHLine(0, 45, display.width() - 1, RED);
  
  display.setCursor(15, 52);
  display.setTextColor(BLUE);
  display.print("PHMARDUINO");
  
  delay(2000); // tempo de 2 sec
}
