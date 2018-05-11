void handlePIR()
{
  if(digitalRead(PIR) == HIGH)
  {
    ledOn(LED1);
  }
}