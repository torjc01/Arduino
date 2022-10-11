/**
* 
*/

// Constants qui definissent le temps 
const int TEMPO_ABERTURA = 3000;  // La porte reste ouverte pendant 3 seconds
const int TEMPO_ESPERA   = 5000;  // Temps d'attente jusqu'au nouveau cycle. 

// Definition de variables de couleurs
const int RED  []  = {255, 0, 0}; // Lumière rouge: alertes d'erreur
const int GREEN[]  = {0, 255, 0}; // Lumière verte: porte ouverte, accès franchi
const int BLUE []  = {0, 0, 255}; // Lumière bleue: 

// Notes musicales
const int LA4 = 440;

// Pin buzzer
const int BUZZ_PIN  = 5;

// Pins LED RGB
const int RED_PIN   = 1;     
const int GREEN_PIN = 2;
const int BLUE_PIN  = 3;

// Pin relay 
const int RELAY_PIN = 4;

// Pins sensor RC522




/**
 * 
 */
void setup() {
  pinMode(RED_PIN, OUTPUT); 
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUZZ_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT); 
}

/**
 * 
 */
void loop() {
  delay(TEMPO_ESPERA);
  open(); 
  delay(TEMPO_ABERTURA);
  close();
}

/**
 * 
 */
void open(){
  tone(BUZZ_PIN, LA4);
  rgbled(GREEN);
  digitalWrite(RELAY_PIN, HIGH);
}

/**
 * 
 */
void close(){
  noTone(BUZZ_PIN);
  rgbled(BLUE); 
  digitalWrite(RELAY_PIN, LOW);
}

/**
 * 
 */
void rgbled(int color[]){
  analogWrite(RED_PIN, color[0]); 
  analogWrite(GREEN_PIN, color[1]);
  analogWrite(BLUE_PIN, color[2]);
}
