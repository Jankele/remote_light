#define LED1 2
#define LED2 3
#define LED3 4
#define PR A0
#define POZIOM 300
#define BAUD 9600

bool state = false;

boolean isBright()
{
  if(analogRead(PR) > POZIOM) //LDR < 300
    return true;
  else
    return false;
}

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

void setup()
{
  pinMode(PR, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  initiateConsole();
}

void loop()
{
  if(isBright())
  {
    if(state == true)
    {
      ledOff(LED1);
      state = false;
    }
  }
  else
  {
    if(state == false)
    {
      ledOn(LED1);
      state = true;
    }
  }
}
