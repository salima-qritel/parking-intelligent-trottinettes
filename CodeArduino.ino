#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Configuration LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Definition des pins des capteurs ultrasoniques
#define TRIG_IN 11   // Trigger capteur entree
#define ECHO_IN 12   // Echo capteur entree
#define TRIG_OUT 2   // Trigger capteur sortie
#define ECHO_OUT 3   // Echo capteur sortie

// Definition du pin du servomoteur
#define SERVO_PIN 9

// Creation objet servomoteur
Servo barrier;

// Variable compteur de trottinettes
int compteur = 0;

// Constante de detection (en cm)
const int SEUIL_DETECTION = 10;

// Fonction de mesure de distance
long distance(int trig, int echo) {
  // Pulse de nettoyage
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  // Generation pulse ultrasonique (10us)
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  // Lecture du temps de retour de l'echo
  long duration = pulseIn(echo, HIGH);
  
  // Calcul de la distance
  // Vitesse du son = 340 m/s = 0.034 cm/us
  // Distance = (temps * vitesse) / 2
  return duration * 0.034 / 2;
}

void setup() {
  // Configuration des pins des capteurs
  pinMode(TRIG_IN, OUTPUT);
  pinMode(ECHO_IN, INPUT);
  pinMode(TRIG_OUT, OUTPUT);
  pinMode(ECHO_OUT, INPUT);
  
  // Initialisation du servomoteur
  barrier.attach(SERVO_PIN);
  barrier.write(0); // Position fermee
  
  // Initialisation de l'ecran LCD
  lcd.init();
  lcd.backlight();
  
  // Affichage initial
  lcd.setCursor(0, 0);
  lcd.print("Scooters :");
  lcd.setCursor(0, 1);
  lcd.print("0");
}

void loop() {
  // Mesure des distances
  long dIn = distance(TRIG_IN, ECHO_IN);
  long dOut = distance(TRIG_OUT, ECHO_OUT);
  
  // Detection entree
  if (dIn < SEUIL_DETECTION) {
    compteur++;
    
    // Ouverture barriere
    barrier.write(90);
    
    // Temporisation pour passage (1 seconde)
    delay(1000);
    
    // Fermeture barriere
    barrier.write(0);
    
    // Mise a jour affichage LCD
    lcd.setCursor(0, 1);
    lcd.print("  "); // Efface anciens chiffres
    lcd.setCursor(0, 1);
    lcd.print(compteur);
    
    // Attente pour eviter double detection
    delay(1000);
  }
  
  // Detection sortie (avec verification compteur > 0)
  if (dOut < SEUIL_DETECTION && compteur > 0) {
    compteur--;
    
    // Ouverture barriere
    barrier.write(90);
    
    // Temporisation pour passage
    delay(1000);
    
    // Fermeture barriere
    barrier.write(0);
    
    // Mise a jour affichage LCD
    lcd.setCursor(0, 1);
    lcd.print("  "); // Efface anciens chiffres
    lcd.setCursor(0, 1);
    lcd.print(compteur);
    
    // Attente pour eviter double detection
    delay(1000);
  }
  
  // Delai avant prochaine lecture
  delay(500);
}
