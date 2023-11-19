void PWM(byte ch, byte pow){
  
//  TCCR2B = TCCR2B & B11111000 | B00000001; // for PWM frequency of 31372.55 HZ D3 D11  
//  TCCR0B = TCCR0B & B11111000 | B00000001; // for PWM frequency of 62500.00 Hz D5 D6
//  TCCR1B = TCCR1B & B11111000 | B00000001; // for PWM frequency of 31372.55 Hz D9 D10

  switch(ch){

    case 0:
        analogWrite(LED_GR_0, pow);
    break;
    
    case 1:
        analogWrite(LED_GR_1, pow);
    break;
    
    case 2:
        analogWrite(LED_GR_2, pow);
    break;
    
    case 3:
        analogWrite(LED_GR_3, pow);
    break;
    
    case 4:
        analogWrite(LED_GR_4, pow);
    break;
    
    case 5:
        analogWrite(LED_GR_5, pow);
    break;
  }
}

void PWMOPP(byte ch, byte pow){
  
//  TCCR2B = TCCR2B & B11111000 | B00000001; // for PWM frequency of 31372.55 HZ D3 D11  
//  TCCR0B = TCCR0B & B11111000 | B00000001; // for PWM frequency of 62500.00 Hz D5 D6
//  TCCR1B = TCCR1B & B11111000 | B00000001; // for PWM frequency of 31372.55 Hz D9 D10

  switch(ch){

    case 0:
        analogWrite(LED_GR_0, pow);
        analogWrite(LED_GR_4, pow);

    break;
    
    case 1:
        analogWrite(LED_GR_1, pow);
        analogWrite(LED_GR_5, pow);

    break;
    
    case 2:
        analogWrite(LED_GR_2, pow);
        analogWrite(LED_GR_3, pow);
    break;
  }
}


void PWMALL(byte pow){
  
  TCCR2B = TCCR2B & B11111000 | B00000001; // for PWM frequency of 31372.55 HZ D3 D11  
  TCCR0B = TCCR0B & B11111000 | B00000001; // for PWM frequency of 62500.00 Hz D5 D6
  TCCR1B = TCCR1B & B11111000 | B00000001; // for PWM frequency of 31372.55 Hz D9 D10

  analogWrite(LED_GR_0, pow);
  analogWrite(LED_GR_1, pow);
  analogWrite(LED_GR_2, pow);
  analogWrite(LED_GR_3, pow);
  analogWrite(LED_GR_4, pow);
  analogWrite(LED_GR_5, pow);
}


void Delay(int mil){

  delay(mil *64);
}


void fadeOutAll(byte startBr, int del){

  for(int i = startBr; i >= 0; i--){
    
    PWMALL(i);
    Delay(del);
  }
}


void fadeOut(byte startBr, int del, bool c0, bool c1, bool c2, bool c3, bool c4, bool c5){

  for(int i = startBr; i >= 0; i--){

    if(c0)
      PWM(0, i);
    if(c1)
      PWM(1, i);
    if(c2)
      PWM(2, i);
    if(c3)
      PWM(3, i);
    if(c4)
      PWM(4, i);
    if(c5)
      PWM(5, i);
    
    Delay(del);
  }
}


void fadeTo(byte startBr, byte endBr, int del, bool c0, bool c1, bool c2, bool c3, bool c4, bool c5){

  for(int i = startBr; i != endBr; i--){

    if(c0)
      PWM(0, i);
    if(c1)
      PWM(1, i);
    if(c2)
      PWM(2, i);
    if(c3)
      PWM(3, i);
    if(c4)
      PWM(4, i);
    if(c5)
      PWM(5, i);
    
    Delay(del);
  }
}


int module(int in){

  return in < 0 ? in * -1 : in;
}
