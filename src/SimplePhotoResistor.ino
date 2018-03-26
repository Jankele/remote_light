int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int PR = A0;

void setup() {
  Serial.begin(9600);
  pinMode(PR, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  Serial.println("Start");

}

void loop() {
  if(analogRead(PIR) < 25) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    Serial.println("Zapalenie swiatla");
    delay(1000);
    Serial.println("Gaszenie swiatel");
  }
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
}
