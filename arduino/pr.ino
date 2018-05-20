void initiatePr()
{
  pinMode(PR, INPUT);
}

bool isBright()
{
  if(analogRead(PR) > POZIOM) //LDR < 200
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
      ledOff(LED1);
      isLedTurnedOn = false;
    }
  }
  else
  {
    if(digitalRead(LED1) == LOW)
    {
      ledOn(LED1);
      isLedTurnedOn = true;
    }
  }
}
