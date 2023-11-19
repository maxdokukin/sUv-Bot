byte waitingGlass(){

  long timer = millis();

  PWMALL(2);
  
  while(millis() - timer < 640000){
    
    if(!digitalRead(SENS_PIN))
      return 2;  
  }
  
  PWMALL(0);
 
  return 0;
}
