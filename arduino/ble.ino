char znak;

void (softReset)
{
asm volatile ("  jmp 0");
}



void loopBLE()
{
    znak = (char)0;

    while(znak == (char)0)
    {
      if(Serial.available())
        znak = (byte)Serial.read();
      delay(10);
    }

    switch(znak)
    {
      case 'a':
      {
        if(digitalRead(LED1) == LOW)
          digitalWrite(LED1, HIGH);
      }
      break;
      
      case 'b':
      {
        if(digitalRead(LED1) == HIGH)
          digitalWrite(LED1, LOW);
      } 
      break;
      
      case 'c':
      {
        if(digitalRead(LED2) == LOW)
          digitalWrite(LED2, HIGH);
      } 
      break;
      
      case 'd':
      {
        if(digitalRead(LED2) == HIGH)
          digitalWrite(LED2, LOW);

      } 
      break;
      
      case 'e':
      {
        if(digitalRead(LED3) == LOW)
          digitalWrite(LED3, HIGH);
      } 
      break;
      
      case 'f':
      {
        if(digitalRead(LED3) == HIGH)
          digitalWrite(LED3, LOW);
      } 
      break;
      case 'g':
        softReset();
      break;
      case '1':
        EEPROM.write(ADDRESS, 1);
      break;
      case '2':
        EEPROM.write(ADDRESS, 2);
      break;
      case '3':
        EEPROM.write(ADDRESS, 3);
      break;
      case '4':
        EEPROM.write(ADDRESS, 4);
      break;
      case '5':
        EEPROM.write(ADDRESS, 5);
      break;
      case '6':
        EEPROM.write(ADDRESS, 6);
      break;
      case '7':
        EEPROM.write(ADDRESS, 7);
      break;
    }
}
