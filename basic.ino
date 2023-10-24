#include <Adafruit_NeoPixel.h>

const int pressSensor = A1;
const int led = 9;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(30, led, NEO_GRB + NEO_KHZ800);
int ledState = 0; // 0: 꺼진상태, 1: 특수등, 2: 일반등, 3: 무드등
const int ledNumber = 30;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(led, OUTPUT);

  strip.begin();
  strip.show();
      
}

void loop() {
  // put your main code here, to run repeatedly:
      
  int value = analogRead(pressSensor);
  Serial.println(value);


  if(value >= 20 && value < 400){ // 압력이 오면
    if(ledState == 0){ // 불이 꺼져있다면
      float r = 245;
      float g = 88;
      float b = 200;
      for(int i = 0; i < 6; i++){
        strip.setPixelColor(i, strip.Color(r, g, b)); // 특수
        strip.show();

        
      }
      for(int i = 6; i < 12; i++){
        strip.setPixelColor(i, strip.Color(r, g, b)); // 특수
        strip.show();
        r -= 27.3;
        g += 27; 
        b += 7.83;
        
      }
      for(int i = 12; i < 18; i++){
        strip.setPixelColor(i, strip.Color(r, g, b)); // 특수
        strip.show();
        r += 27.3;
        g -= 24.8;
        b -= 27.3;
       
      }
      for(int i = 18; i < 24; i++){
        strip.setPixelColor(i, strip.Color(r, g, b)); // 특수
        strip.show();

         r -= 25.3;
        g += 25.1;
        b -= 13.3;
      }
      for(int i = 24; i < ledNumber; i++){
        strip.setPixelColor(i, strip.Color(r, b, g)); // 특수
        strip.show();

        r += 11.2;
        g -= 22.5;
        b -= 9.1;
      }

      ledState = 1;
    }else if(ledState == 1){
      for(int i = 0; i < ledNumber; i++){
        strip.setPixelColor(i, strip.Color(233, 243, 241)); // 일반등
        strip.show();  
      }     

      ledState = 2;
    }else if(ledState == 2){
      for(int i = 0; i < ledNumber; i++){
        strip.setPixelColor(i, strip.Color(181, 137, 33)); // 무드등
        strip.show();
      }     
      
      ledState = 3;
    }else{
      for(int i = 0; i < ledNumber; i++){
        strip.setPixelColor(i, strip.Color(0, 0, 0)); // 끔
        strip.show();
      }
      
      ledState = 0;
    }
  }
  delay(250);  
}
