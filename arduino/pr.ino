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

void handlePr()
{
  if(isBright())
  {
    if(state == true)
    {
      ledOff(LED1);
      ledState = false;
    }
  }
  else
  {
    if(state == false)
    {
      ledOn(LED1);
      ledState = true;
    }
  }
}
