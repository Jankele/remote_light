void initiatePr()
{
  pinMode(PR, INPUT);
}

bool isBright()
{
  if(analogRead(PR) > POZIOM)
    return true;
  else
    return false;
}

void handlePr()
{
  if(isBright())
  {
    if(digitalRead(LED1) == HIGH)
    {
      Serial.print("b");
      ledOff(LED1);
      isLedTurnedOn = false;
    }
  }
  else
  {
    if(digitalRead(LED1) == LOW)
    {
      Serial.print("a");
      ledOn(LED1);
      isLedTurnedOn = true;
    }
  }
}
