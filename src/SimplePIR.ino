int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int PIR = 7;

void setup() {
  Serial.begin(9600);
  pinMode(PIR, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  Serial.println("Kalibrowanie Sensora PIR");
  delay(500);
  Serial.println("Czekaj 15 sekund");
  for(int i=1;i<15;i++) {
  Serial.print(".");
  delay(1000);
  }
  Serial.println("Start");

}

void loop() {
  if(digitalRead(PIR) == HIGH) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    Serial.println("Wykryto ruch");
    delay(1000);
    Serial.println("Gaszenie swiatel");
  }
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
}
