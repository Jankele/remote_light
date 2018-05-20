void loopSwitch()
{
  switch (configuration)
  {
    case EPR: //done - tested - working
    {
      handleConfig();
      handlePr();
    }
    break;
      
    case EPIR: //done - tested - working
    {
      handleConfig();
      loopEpir();
    }
    break;
      
    case EBLE: //done - tested - working
      loopEble();
    break;
      
    case EPR_PIR: //done - tested - working
    {
      handleConfig();
      loopEpr_pir();
    }
    break;

    case EPR_BLE: //done - tested - working
      loopEpr_ble();
    break;

    case EPIR_BLE: //done - tested - working
      loopEpir_ble();
    break;

    default: //done - tested - working
      loopEpr_pir_ble();
  }
}
