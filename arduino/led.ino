void initiateLed()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void ledOn(uint8_t Led)
{
  digitalWrite(Led, HIGH);
}

void ledOff(uint8_t Led)
{
  digitalWrite(Led, LOW);
}
