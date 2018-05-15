void initiatePir()
{
  pinMode(PIR, INPUT);
  delay(1000); // kalibracja czujki pir
}

void handlePir()
{
  if(digitalRead(PIR) == HIGH)
  {
    ledOn(LED1);
    ledState = true;
  }
  else
  {
    ledState = false;
  }
}
