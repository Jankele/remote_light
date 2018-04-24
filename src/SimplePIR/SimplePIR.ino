#define LED1 2
#define LED2 3
#define LED3 4
#define PIR 8
#define BAUD 9600

void ledOn(uint8_t Led)
{
  digitalWrite(Led, HIGH);
}

void ledOff(uint8_t Led)
{
  digitalWrite(Led, LOW);
}
void initiateConsole()
{
  Serial.begin(BAUD);
  while(! Serial); //Czekanie na konsole
}

void initiateLED()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

loopPIR()
{
    if(digitalRead(PIR) == HIGH)
  {
    ledOn(LED1);
    ledOn(LED2);
    ledOn(LED3);
    delay(1000);
    ledOff(LED1);
    ledOff(LED2);
    ledOff(LED3);
  }
}

void setup() {
  pinMode(PIR, INPUT);
  initiateLED();
  initiateConsole();
}

void loop()
{
  loopPIR();
}
