bool state = false;

boolean isBright()
{
  if(analogRead(PR) > POZIOM) //LDR < 300
    return true;
  else
    return false;
}

void loopPR()
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