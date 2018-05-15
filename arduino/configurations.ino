//pr - done
void loopEpir() //done?
{
  handlePir();
  if(ledState = true)
  {
    previousTime = millis();
  }
  else
  {
    currentTime = millis();
    if(currentTime - previousTime > maxInterval)
    {
      if(digitalRead(LED1) == HIGH)
      {
        ledOff(LED1);
      }
    }
  }
}

void loopEble() //done
{
  handleBle();
}

void loopEpir_pr() //done
{
  handlePr();
  loopEpir();
}

void loopEpr_ble()
{
  previousTime = millis();
//  currentTime = millis();
  handleBle();
  handlePR();
}

void loopEpir_ble()
{
  handlePir();
  handleBle();
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
      loopEpir_pr();
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
      loopEpir_ble();
      handleConfig();
    }
    break;

    default:
    {
      handleConfig();
      loopEpr_pir_ble();
    }
  }
}
