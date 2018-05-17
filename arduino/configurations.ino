//everything to review before compilation
//pr - done
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
    if(currentTimePIr - previousTimePir > maxInterval)
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
    currentTime = millis();
    if(currentTime - previousTime > maxInterval)
    {
      isBleUsed = false;
    }
  }
  else
  {
    handlePR();
    previousTime = millis();
  }
}

void loopEpir_ble() //need to be tested
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
}

void loopEpr_pir_ble()
{
  handlePr();
  handlePir();
  handleBle();
}

void loopSwitch()
{
  switch (configuration)
  {
    case EPR:
    {
      handleConfig();
      handleEpr();
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
