void loopEpir() //done
{
  handlePir();
  if(digitalRead(LED2) == HIGH)
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

void loopEble() //done
{
  handleBle();
}

void loopEpr_pir() //done
{
  handlePr();
  loopEpir();
}

void loopEpr_ble() //done
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

void loopEpir_ble() //done
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

void loopSwitch()
{
  switch (configuration)
  {
    case EPR:
    {
      handleConfig();
      handlePr();
    }
    break;
      
    case EPIR:
    {
      handleConfig();
      loopEpir();
    }
    break;
      
    case EBLE:
      loopEble();
    break;
      
    case EPIR_PR:
    {
      handleConfig();
      loopEpr_pir();
    }
    break;

    case EPR_BLE:
    {
      handleConfig();
      loopEpr_ble();
    }
    break;

    case EPIR_BLE:
    {
      handleConfig();
      loopEpir_ble();
    }
    break;

    default:
    {
      handleConfig();
      loopEpr_pir_ble();
    }
  }
}
