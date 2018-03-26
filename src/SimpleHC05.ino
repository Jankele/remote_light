int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int HC = 0;
int BAUD = 9600;
char znak;

void setup() {
  pinMode(PR, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  Serial.begin(BAUD);
  while(! Serial); //Czekanie na konsole
  if(Serial.available()) {
  Serial.println("Start");
  }
}

void loop() {
  Serial.println("a = Dioda pierwsza ON, b = Dioda pierwsza OFF");
  delay(100);
  Serial.println("c = Dioda druga ON, d = Dioda pierwsza OFF");
  delay(100);
  Serial.println("e = Dioda trzecia ON, f = Dioda trzecia OFF");
  znak = Serial.read();
  switch(znak) {
    
    case 'a':
    {
    if(digitalRead(LED1) == 0) {
      digitalWrite(LED1, HIGH);
      Serial.println("Zapalam LED 1"); }
    }
    break;
    
    case 'b':
    {
    if(digitalRead(LED1) == 1) {
      digitalWrite(LED1, LOW);
      Serial.println("Gasze LED 1"); }
    } 
    break;
    
    case 'c':
    {
    if(digitalRead(LED2) == 0) {
      digitalWrite(LED2, HIGH);
      Serial.println("Zapalam LED 2"); }
    } 
    break;
    
    case 'd':
    {
    if(digitalRead(LED2) == 1) {
      digitalWrite(LED2, LOW);
      Serial.println("Gasze LED 2"); }
    } 
    break;
    
    case 'b':
    {
    if(digitalRead(LED3) == 0) {
      digitalWrite(LED3, HIGH);
      Serial.println("Zapalam LED 3"); }
    } 
    break;
    
    case 'b':
    {
    if(digitalRead(LED1) == 1) {
      digitalWrite(LED1, LOW);
      Serial.println("Gasze LED 3"); }
    } 
    break;
  }
  Serial.println("Resetowanie");
  delay(1000);
  Serial.flush();
}
