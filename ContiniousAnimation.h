byte fadeInOut();
byte fadeCircular();

byte continiousAnimation(){

  //fade in/out 5 times
  
  while(1){

    if(fadeInOut())
      return 3;
  }


  
//  //circular fades
//  for(int c = 0; c < 5; c++){
//      
//    if(fadeCircular())
//      return 3;
    
  //}


  //random fades

  return 2; //glass still on
}


byte fadeCircular(){

  for(int deg = 0; deg < 360; deg++){

    byte br1 = 0, br2 = 0, br3 = 0;
    
    if(digitalRead(SENS_PIN)){
        
      fadeOutAll(100, 3);
        
      return 3;
    }

    //group 1
    if(deg >= 0 && deg <= 60)
      br1 = map(module(deg - 30), 0 , 30, 255, 50);
        
    else if(deg > 60 && deg <= 180)
      br1 = map(deg, 60 , 180, 50, 10);
      
    else if(deg > 180 && deg <= 240)
      br1 = map(module(deg - 210), 0 , 30, 3, 10);

    else if(deg > 240 && deg < 360)
      br1 = map(deg, 240, 360, 10, 50);


    //group 2
    if(deg >= 120 && deg <= 180)
      br2 = map(module(deg - 150), 0 , 30, 255, 50);
        
    else if(deg > 180 && deg <= 300)
      br2 = map(deg, 180, 300, 50, 10);
      
    else if(deg > 300 && deg < 360)
      br2 = map(module(deg - 330), 0 , 30, 3, 10);

    else if(deg >= 0 && deg < 120)
      br2 = map(deg, 0, 120, 10, 50);


    //group 3
    if(deg >= 240 && deg <= 300)
      br3 = map(module(deg - 270), 0 , 30, 255, 50);
        
    else if(deg > 300 && deg < 360)
      br3 = map(deg, 300 , 360, 50, 30);

    else if(deg >= 0 && deg <= 60)
      br3 = map(deg, 0 , 60, 30, 10);
    
    else if(deg > 60 && deg <= 120)
      br3 = map(module(deg - 90), 0 , 30, 3, 10);

    else if(deg > 120 && deg < 240)
      br3 = map(deg, 120, 240, 10, 50);

Serial.print(deg); Serial.print("   "); Serial.println(br1);
    
    PWMOPP(0, br1);
    PWMOPP(1, br2);
    PWMOPP(2, br3);
    Delay(20);
  }

  
  
}


byte fadeInOut(){
  
  for(int i = 3; i <= 255; i++){ // fade in
      
      if(digitalRead(SENS_PIN)){
        
        fadeOutAll(i, 3);
        
        return 3;
      }
      
      PWMALL(i);
      Delay(10);
    }  
    
    for(int i = 255; i > 2; i--){ // fade out
  
      if(digitalRead(SENS_PIN)){

        fadeOutAll(i, 3);
        return 3;
      }
        
      PWMALL(i);
      Delay(10);
    }  

    return 0;
}
