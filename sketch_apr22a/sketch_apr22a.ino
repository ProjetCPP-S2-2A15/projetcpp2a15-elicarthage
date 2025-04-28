#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int bouton1 = 2; // bouton suivant
const int bouton2 = 3; // bouton bienvenue

String* noms = nullptr;
int index = 0;          // nombre total de noms
int lectureIndex = 0;   // index de lecture circulaire
bool premierNomAffiche = false;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("En attente...");

  pinMode(bouton1, INPUT_PULLUP);
  pinMode(bouton2, INPUT_PULLUP);
}

void loop() {
  // Réception série
  if (Serial.available()) {
    String ligne = Serial.readStringUntil('\n');
    ligne.trim();
    
    if (ligne == "CLEAR") {
  
      delete[] noms;
      noms = nullptr;
      index = 0;
      lectureIndex = 0;
      premierNomAffiche = false;
      lcd.clear();
     
    }
    else if (ligne.length() > 0) {
      // Normal : ajout d'un nouveau nom
      String* nouveauxNoms = new String[index + 1];
      for (int i = 0; i < index; i++) {
        nouveauxNoms[i] = noms[i];
      }
      nouveauxNoms[index] = ligne;
      index++;
      delete[] noms;
      noms = nouveauxNoms;

      if (!premierNomAffiche) {
        lcd.clear();
        lcd.print(noms[lectureIndex]);
        premierNomAffiche = true;
      }
    }
  }

  // Bouton 2 → Affiche "Bienvenue" + nom actuel et supprime le nom après
  if (digitalRead(bouton2) == LOW) {
    if (index > 0) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Bienvenue:");
      lcd.setCursor(0, 1);
      lcd.print(noms[lectureIndex]);
      Serial.println(noms[lectureIndex]);
      delay(2000);

      for (int i = lectureIndex; i < index - 1; i++) {
        noms[i] = noms[i + 1];
      }
      index--;

      if (lectureIndex >= index) {
        lectureIndex = 0;
      }

      lcd.clear();
      if (index > 0) {
        lcd.print(noms[lectureIndex]);
      } else {
        lcd.print("En attente...");
        premierNomAffiche = false;
      }
      delay(1000);
    }
  }

  // Bouton 1 → avancer
  if (digitalRead(bouton1) == LOW) {
    if (index > 0) {
      lectureIndex++;
      if (lectureIndex >= index) {
        lectureIndex = 0;
      }
      lcd.clear();
      lcd.print(noms[lectureIndex]);
      delay(300);
    }
  }
}