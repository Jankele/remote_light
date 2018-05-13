void initiatePir()
{
  pinMode(PIR, INPUT);
  delay(1000); // kalibracja czujki pir
}

bool handlePir()
{
  if(digitalRead(PIR) == HIGH)
  {
    ledOn(LED1);
    return true;
  }
  else
  {
    return false;
  }
}
