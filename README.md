# feu-rouge-arduino-avec-pietons-tp-18

liste du materiel utillisé :
  - 5 led :
     - 2 rouges
     - 1 jaune
     - 2 vert
  - 6 resistance :
     - 5x 330 ohms
     - 1x 10k ohms
  - 8 cable conducteur
  - 1 bouton poussoir
  - 1 arduino uno R3
  - 1 breadboard
  - 1 cable USB type A <--> USB type B
  - 1 ordinateur
    
BRANCHEMENTS :

  - led :
    - verte pietons : H-30 --> Borne négative (2)       # Led verte pietons
    - rouge pietons : H-28 --> Borne négative (2)       # Led rouge pietons
    - verte voiture : H-20 --> Borne négative (2)       # Led verte voitures
    - jaune voiture : H-18 --> Borne négative (2)       # Led jaune voitures
    - rouge voiture : H-16 --> Borne négative (2)       # Led rouge voitures
  - resistance :
     - 330 ohms :
         - C-30 <--> F-30                               # entre led verte pietons et cable conducteur
         - C-28 <--> F-28                               # entre led rouge pietons et cable conducteur
         - C-21 <--> F-20                               # entre led verte voitures et cable conducteur
         - C-19 <--> F-18                               # entre led jaune voitures et cable conducteur
         - C-17 <--> F-16                               # entre led rougev oitures et cable conducteur
      - 10k ohms : 
          - J-8 <-->  Borne négative (2)                # entre bouton possoir et borne negative (2)
 - Bouton poussoir E-6 E-8 <--> H-6 H-8
 - cable conducteur :
     - A-30 <--> PIN-7                                   # Led verte pietons
     - A-28 <--> PIN 8                                   # Led rouge pietons
     - A-21 <--> PIN-4                                   # Led verte voitures
     - A-19 <--> PIN-5                                   # Led jaune voitures
     - A-17 <--> PIN-6                                   # Led rouge voitures
     - I-6 <--> PIN-2                                    # Bouton poussoir
     - Borne négative (1) <--> GND                       # Lien negatif entre breadbord et arduino
     - Borne négative (1) <--> Borne négative (2)        # Lien entre borne negative (1) <--> borne negative (2) du breadbord

    
