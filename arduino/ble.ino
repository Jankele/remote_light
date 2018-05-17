void (softReset)
{
asm volatile ("  jmp 0");
}

void initiateConsole()
{
  Serial.begin(BAUD);
  while(! Serial); //Czekanie na konsole
}

void handleBLE()
{
  if(Serial.available())
    serialHolder = (byte)Serial.read();

  switch(serialHolder)
  {
    case 'a': //pr
    {
      if(digitalRead(LED1) == LOW)
        digitalWrite(LED1, HIGH);
      isBleUsed = true;
    }
    break;

    case 'b': //pr
    {
      if(digitalRead(LED1) == HIGH)
        digitalWrite(LED1, LOW);
      isBleUsed = true;
    } 
    break;
    
    case 'c': //pir
    {
      if(digitalRead(LED2) == LOW)
        digitalWrite(LED2, HIGH);
      isBleUsed = true;
    } 
    break;
    
    case 'd': //pir
    {
      if(digitalRead(LED2) == HIGH)
        digitalWrite(LED2, LOW);
      isBleUsed = true;
    } 
    break;
    
    case 'e': //ble
    {
      if(digitalRead(LED3) == LOW)
        digitalWrite(LED3, HIGH);
    } 
    break;
      
    case 'f': //ble
    {
      if(digitalRead(LED3) == HIGH)
        digitalWrite(LED3, LOW);
    } 
    break;
    
    case 'g': //reset
      softReset();
    break;
    
    case 'h': //konfiguracja pr
      EEPROM.write(ADDRESS, 1);
    break;
    
    case 'i': //konfiguracja pir
      EEPROM.write(ADDRESS, 2);
    break;
    
    case 'j': //konfiguracja ble
      EEPROM.write(ADDRESS, 3);
    break;
    
    case 'k': //konfiguracja pr_pir
      EEPROM.write(ADDRESS, 4);
    break;
    
    case 'l': //konfiguracja pr_ble
      EEPROM.write(ADDRESS, 5);
    break;
    
    case 'm': //konfiguracja pir_ble
      EEPROM.write(ADDRESS, 6);
    break;
    
    case 'n': //konfiguracja pr_pir_ble
      EEPROM.write(ADDRESS, 7);
    break;
    }
}

void handleConfig()
{
  if(Serial.available())
     serialHolder = (byte)Serial.read();

  switch(serialHolder)
  {
    case 'g':
      softReset();
    break;
    case 'h':
      EEPROM.write(ADDRESS, 1);
    break;
    case 'i':
      EEPROM.write(ADDRESS, 2);
    break;
    case 'j':
      EEPROM.write(ADDRESS, 3);
    break;
    case 'k':
      EEPROM.write(ADDRESS, 4);
    break;
    case 'l':
      EEPROM.write(ADDRESS, 5);
    break;
    case 'm':
      EEPROM.write(ADDRESS, 6);
    break;
    case 'n':
      EEPROM.write(ADDRESS, 7);
    break;
  }
}