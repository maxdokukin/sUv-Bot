#define SENS_PIN 2
#define LED_GR_0 3
#define LED_GR_1 5
#define LED_GR_2 6
#define LED_GR_3 9
#define LED_GR_4 10
#define LED_GR_5 11

#include "GeneralFunctions.h"
#include "WelcomeAnimation.h"
#include "ContiniousAnimation.h"
#include "WaitingGlass.h"


void setup() {

  pinMode(SENS_PIN, INPUT_PULLUP);
  
  TCCR2B = TCCR2B & B11111000 | B00000001; // for PWM frequency of 31372.55 HZ D3 D11  
  TCCR0B = TCCR0B & B11111000 | B00000001; // for PWM frequency of 62500.00 Hz D5 D6
  TCCR1B = TCCR1B & B11111000 | B00000001; // for PWM frequency of 31372.55 Hz D9 D10

  pinMode(LED_GR_0, OUTPUT);
  pinMode(LED_GR_1, OUTPUT);
  pinMode(LED_GR_2, OUTPUT);
  pinMode(LED_GR_3, OUTPUT);
  pinMode(LED_GR_4, OUTPUT);
  pinMode(LED_GR_5, OUTPUT);

  Serial.begin(9600);


}


byte state = 0;


void loop() {

  switch(state){

      //No glass
      case 0: 
        state = !digitalRead(SENS_PIN);
      break;


      //Welcome animation
      case 1: 
        state = welcomeAnimation();
      break;

      //Continiuos animation
      case 2: 
        state = continiousAnimation();
      break;

      
      //Waiting for glass back
      case 3: 
        state = waitingGlass();
      break;
  }
  
  delay(5);
}
