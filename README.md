# 🚲 Parking Intelligent de Trottinettes Électriques (Arduino & IoT)

Ce projet présente la conception et la réalisation d’un **système de parking intelligent pour trottinettes électriques**, basé sur la plateforme **Arduino Uno** et des composants IoT simples.  
Le système permet de détecter automatiquement les entrées et sorties, de compter le nombre de trottinettes présentes et de contrôler une barrière motorisée avec affichage en temps réel.

---

## 📌 Objectifs du Projet

- Détecter automatiquement l’entrée et la sortie des trottinettes
- Compter en temps réel le nombre de trottinettes présentes
- Contrôler l’accès via une barrière motorisée
- Afficher les informations sur un écran LCD
- Proposer une solution simple, économique et automatisée

---

## 🛠️ Matériel Utilisé

- **Arduino Uno**
- **2 × Capteurs ultrasoniques HC-SR04**
- **Servomoteur (barrière d’accès)**
- **Écran LCD 16x2 avec module I2C**
- Breadboard
- Fils Dupont (mâle–mâle et mâle–femelle)
- Alimentation 5V

---

## ⚙️ Principe de Fonctionnement

- Un capteur ultrasonique détecte l’entrée des trottinettes
- Un second capteur détecte la sortie
- Lorsqu’une trottinette est détectée :
  - Le compteur est mis à jour
  - La barrière s’ouvre automatiquement
  - L’écran LCD affiche le nombre actuel de trottinettes
- Le système fonctionne en boucle continue avec une temporisation anti-rebond

---

## 🔌 Connexions des Composants

| Composant | Broches Arduino |
|---------|----------------|
| HC-SR04 (Entrée) | TRIG → 11, ECHO → 12 |
| HC-SR04 (Sortie) | TRIG → 2, ECHO → 3 |
| Servomoteur | PWM → 9 |
| LCD I2C | SDA → A4, SCL → A5 |

---

### Bibliothèques utilisées
- `Wire.h`
- `LiquidCrystal_I2C.h`
- `Servo.h`

---


## 🧪 Tests et Résultats

- Détection fiable des entrées et sorties
- Barrière fonctionnelle et synchronisée avec les capteurs
- Affichage LCD clair et mis à jour en temps réel
- Système stable et réactif

---


## 👩‍💻 Auteur

**QRITEL Salima**  
Projet académique – Arduino & IoT  



