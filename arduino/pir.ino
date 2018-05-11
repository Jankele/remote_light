void loopPIR()
{
  if(digitalRead(PIR) == HIGH)
  {
    ledOn(LED1);
  }
}
