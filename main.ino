#define T_VERT_MAX 5000
#define T_VERT_MIN 2000
#define T_ORANGE 2000
#define T_PIETON 5000

const int vertVoiture = 4;
const int orangeVoiture = 5;
const int rougeVoiture = 6;

const int vertPieton = 7;
const int rougePieton = 8;

const int bouton = 2;

bool demandePieton = false;

void setup() {
  pinMode(vertVoiture, OUTPUT);
  pinMode(orangeVoiture, OUTPUT);
  pinMode(rougeVoiture, OUTPUT);

  pinMode(vertPieton, OUTPUT);
  pinMode(rougePieton, OUTPUT);

  pinMode(bouton, INPUT_PULLUP);
}

void loop() {
  sequenceVoiture();
  sequencePieton();
}

void sequenceVoiture() {
  // Feu voiture vert
  digitalWrite(vertVoiture, HIGH);
  digitalWrite(orangeVoiture, LOW);
  digitalWrite(rougeVoiture, LOW);

  // Feu piéton rouge
  digitalWrite(vertPieton, LOW);
  digitalWrite(rougePieton, HIGH);

  unsigned long debut = millis();

  while (millis() - debut < T_VERT_MAX) {
    if (digitalRead(bouton) == LOW) {
      demandePieton = true;
    }

    // si une demande a été faite et que le vert minimum est atteint,
    // on quitte plus tôt la phase verte
    if (demandePieton && (millis() - debut >= T_VERT_MIN)) {
      break;
    }
  }

  // Orange voiture
  digitalWrite(vertVoiture, LOW);
  digitalWrite(orangeVoiture, HIGH);
  digitalWrite(rougeVoiture, LOW);
  delay(T_ORANGE);

  // Rouge voiture
  digitalWrite(vertVoiture, LOW);
  digitalWrite(orangeVoiture, LOW);
  digitalWrite(rougeVoiture, HIGH);

  digitalWrite(vertPieton, HIGH);
  digitalWrite(rougePieton, LOW);
}

void sequencePieton() {
  // Si personne n'a appuyé, petit rouge voiture puis retour au cycle
  if (!demandePieton) {
    delay(5000);
    return;
  }

  // Passage piéton
  digitalWrite(rougePieton, LOW);
  digitalWrite(vertPieton, HIGH);
  delay(T_PIETON);

  // Fin passage piéton
  digitalWrite(vertPieton, LOW);
  digitalWrite(rougePieton, HIGH);

  // On efface la demande
  demandePieton = false;
}
