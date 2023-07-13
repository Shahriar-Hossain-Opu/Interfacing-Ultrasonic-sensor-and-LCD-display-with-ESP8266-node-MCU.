#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define echoPin 14 // D5
#define trigPin 12 // D6
long duration;
int distance;

void setup() {
  Wire.begin(2, 0);//D3 SCL D4-SDA
  lcd.begin();
  lcd.backlight();

  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  duration=pulseIn(echoPin,HIGH);
  distance=(duration*0.034/2);

  if(distance < 20){
      digitalWrite(LED_BUILTIN, LOW);
    } else{
        digitalWrite(LED_BUILTIN, HIGH);
    }
    
  lcd.print("Distance : ");
  lcd.print(distance);
  lcd.print(" cm");
  delay(1000); 
  lcd.clear();
}
