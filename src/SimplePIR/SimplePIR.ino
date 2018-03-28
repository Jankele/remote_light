#define LED1 2
#define LED2 3
#define LED3 4
#define PIR 8
#define BAUD 9600

void ledOn(uint8_t Led)
{
  digitalWrite(Led, HIGH);
  Serial.print("Wlaczam LED nr ");
  Serial.println(Led);
}

void ledOff(uint8_t Led)
{
  digitalWrite(Led, LOW);
  Serial.print("Wylaczam LED nr ");
  Serial.println(Led);
}
void initiateConsole()
{
  Serial.begin(BAUD);
  while(! Serial); //Czekanie na konsole
  if(Serial.available()) {
    Serial.println("Kalibrowanie Sensora PIR");
    delay(500);
    Serial.println("Czekaj 10 sekund");
    delay(10000);
    Serial.println("Start");
  }
}

void setup() {
  pinMode(PIR, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  initiateConsole();
}

void loop()
{
  if(digitalRead(PIR) == HIGH)
  {
    ledOn(LED1);
    //ledOn(LED2);
    //ledOn(LED3);
    delay(1000);
    ledOff(LED1);
    //ledOff(LED2);
    //ledOff(LED3);
  }
}
