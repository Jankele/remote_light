void initiateLed()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
}

void ledOn(uint8_t Led)
{
  digitalWrite(Led, HIGH);
}

void ledOff(uint8_t Led)
{
  digitalWrite(Led, LOW);
}
