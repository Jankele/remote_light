void loopEpir()
{
  handlePir();
  if(isPirUsed == true)
  {
    previousTimePir = millis();
  }
  else
  {
    currentTimePir = millis();
    if(currentTimePir - previousTimePir > maxInterval)
    {
      if(digitalRead(LED2) == HIGH)
      {
        ledOff(LED2);
      }
    }
  }
}

void loopEble()
{
  handleBle();
}

void loopEpr_pir()
{
  handlePr();
  loopEpir();
}

void loopEpr_ble()
{
  handleBle();
  if(isBleUsed == true)
  {
    currentTimePr = millis();
    if(currentTimePr - previousTimePr > maxInterval)
    {
      isBleUsed = false;
    }
  }
  else
  {
    handlePr();
    previousTimePr = millis();
  }
}

void loopEpir_ble()
{
  handleBle();
  if(isBleUsed == true)
  {
    currentTime = millis();
    if(currentTime - previousTime > maxInterval)
    {
      isBleUsed = false;
    }
  }
  else
  {
    loopEpir();
    previousTime = millis();
  }
}

void loopEpr_pir_ble()
{
loopEpir_ble();
loopEpr_ble();
}
