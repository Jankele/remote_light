void initiatePr()
{
  pinMode(PR, INPUT);
  ledState = false;
}

bool isBright()
{
  if(analogRead(PR) > POZIOM) //LDR < 300
    return true;
  else
    return false;
}

bool handlePr()
{
  if(isBright())
  {
    if(digitalRead(LED2) == HIGH)
    {
      ledOff(LED1);
      return false;
    }
  }
  else
  {
    if(digitalRead(LED2) == LOW)
    {
      ledOn(LED2);
      return true;
    }
  }
}
