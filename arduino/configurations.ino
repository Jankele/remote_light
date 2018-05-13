void loopEpir()
{
  if(handlePir())
  {
    previousTime = millis();
  }
  else
  {
    currentTime = millis();
    if(currentTime - previousTime > INTERVAL)
    {
      ledOff(LED1);
    }
  }
}

void loopEble()
{
  handleBle();
}

void loopEpir_pr()
{
  handlePr();
  handlePir();
}

void loopEpr_ble()
{
  handlePr();
  handleBle();
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
      handleEpr();
    break;
      
    case EPIR: 
      loopEpir();
    break;
      
    case EBLE:
      loopEble();
    break;
      
    case EPIR_PR:
      loopEpir_pr();
    break;

    case EPR_BLE:
      loopEpr_ble();
    break;

    case EPIR_BLE:
      loopEpir_ble();
    break;

    default:
      loopEpr_pir_ble();
  }
}
