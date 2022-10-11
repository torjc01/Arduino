int buzzer = 10;
int pot = A0;
int x;
void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  x = analogRead(pot) / 102,4;

  Serial.println(x);
  digitalWrite(buzzer, HIGH);
  delay(x);
  digitalWrite(buzzer, LOW);
  delay(x);
}
