int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int HC = 0;
int BAUD = 9600;
char znak;

void setup() {
  delay(1000);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  Serial.begin(BAUD);
  while(!Serial){}
  delay(100);
  Serial.println("Start");
}

void loop() {
  delay(50);
    Serial.println("a = LED1 ON, b = LED1 OFF");
    Serial.println("c = LED2 ON, d = LED2 OFF");
    Serial.println("e = LED3 ON, f = LED3 OFF");
    Serial.println("Podaj litere");
    while(znak == (char)0)
    {
      if(Serial.available())
      {
        znak = (char)Serial.read();
        Serial.println(znak);
      }
      delay(100);
    }
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
      
      case 'e':
      {
      if(digitalRead(LED3) == 0) {
        digitalWrite(LED3, HIGH);
        Serial.println("Zapalam LED 3"); }
      } 
      break;
      
      case 'f':
      {
      if(digitalRead(LED3) == 1) {
        digitalWrite(LED3, LOW);
        Serial.println("Gasze LED 3"); }
      } 
      break;
    }
    znak = (char)0;
    delay(50);  
}
