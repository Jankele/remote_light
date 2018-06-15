void initiatePir()
{
  pinMode(PIR, INPUT);
  delay(1000);
}

void handlePir()
{
  if(digitalRead(PIR) == HIGH)
  {
    Serial.print("c");
    ledOn(LED2);
    isPirUsed = true;
  }
  else
  {
    isPirUsed = false;
  }
}
