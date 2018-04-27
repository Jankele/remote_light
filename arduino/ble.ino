char znak;

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
    }
}