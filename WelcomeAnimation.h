byte welcomeAnimation(){

  Serial.println("Welcome");
  
  for(int i = 0; i <= 255; i++){

    if(digitalRead(SENS_PIN)){
        
        fadeOut(i, 3, 1, 0, 0, 0, 1, 0);
        return 0;
    }
      
    PWM(0, i);
    PWM(4, i);

    //Serial.println(i);
    Delay(5);
  }

  for(int i = 0; i <= 255; i++){
    
    if(digitalRead(SENS_PIN)){

        fadeTo(255, i, 3, 1, 0, 0, 0, 1, 0);
        fadeOut(i, 3, 1, 1, 0, 0, 1, 1);
        return 0;
    }    
    
    PWM(1, i);
    PWM(5, i);

    Delay(5);
  }

  for(int i = 0; i <= 255; i++){
    
    if(digitalRead(SENS_PIN)){

        fadeTo(255, i, 3, 1, 1, 0, 0, 1, 1);
        fadeOutAll(i, 3);
        return 0;
    }    
    
    PWM(2, i);
    PWM(3, i);
    
    Delay(5);
  }

  for(int i = 255; i > 2; i--){
    
    if(digitalRead(SENS_PIN)){
        
        fadeOutAll(i, 3);
        return 0;
    }    
    
    PWMALL(i);
    Delay(5);
  }  
  
  return 2;
}
