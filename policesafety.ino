//define variables
int distance = 0;
int level=0;
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}
//import LiquidCrystal library
#include<LiquidCrystal.h>

//create instance, pass pin numbers
//RS, EN, D4,D5,D6,D7
LiquidCrystal lcd(4,A1,A2,A3,A4,A5);


void setup()
{
  Serial.begin(9600);
  //pinMode(pin number,mode);
  pinMode(A0, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
  lcd.begin(16,2);
}

void loop()
{
  distance = 0.01723 * readUltrasonicDistance(3,2);//formula to calculate distance
  //displays distance on serial monitor
  Serial.print("Distance=");
  Serial.println(distance);
  delay(10);// Delay a little bit to improve simulation performance
  Serial.available();
  analogWrite(13,0);
  analogWrite(6,0);
  analogWrite(7,0);
  analogWrite(8,0);
  analogWrite(9,0);
  analogWrite(10,0);
  analogWrite(11,0);
  analogWrite(5,0);
  if(distance<30 && distance>5)//when person approaches kiosk
  {
    digitalWrite(13,HIGH);//white LEDs are turned ON
    lcd.begin(16, 2);//instruction is displayed in lcd
    lcd.setCursor(2,0);
    lcd.print("PLEASE STEP");
    lcd.setCursor(5,1);
    lcd.print("CLOSER");
    delay(100);
  }
  else if(distance<5)//when person is less than 5cm from the alcohol detector
  {
    Serial.available();
    lcd.begin(16, 2);//instruction displayed in LCD
    lcd.setCursor(1,0);
    lcd.print("BLOW WHEN YOU");
    lcd.setCursor(1,1);
    lcd.print("HEAR BEEP SOUND");
    delay(100);
    digitalWrite(13,LOW);//white LEDs are turned OFF
    digitalWrite(6,HIGH);//green LED is ON
    digitalWrite(5,HIGH);//buzzer is ON
    tone(5,523,50);//buzzer produces sound
    delay(10);
    //displays alcohol level on serial monitor
    Serial.print("Alcohol level=");
    Serial.println(analogRead(A0));
    level=analogRead(A0);
    //checks alcohol level and suitably ONs LED bulbs depending on level of alcohol
    if(level>=20)
    {
      digitalWrite(7, HIGH);
      {
        lcd.begin(16,2);
        if(level>25)
        {
         digitalWrite(8, HIGH);
         if(level>35)
         {
          digitalWrite(9, HIGH);
          if(level>60)
          {
            digitalWrite(10, HIGH);
            if(level>100)
            {
              digitalWrite(11, HIGH);
            }
          }
         }
        }
      }
    }
    delay(100);
    //displays level on consumption on a scale of 0-10 on LCD display
    if(level<23)
    {
      lcd.begin(16, 2);
      lcd.setCursor(2,0);
      lcd.print("CONSUMPTION");
      lcd.setCursor(4,1);
      lcd.print("LEVEL 0");
      delay(500);
    }
    if(level>=23 && level<25)
    {
      lcd.begin(16, 2);
      lcd.setCursor(2,0);
      lcd.print("CONSUMPTION");
      lcd.setCursor(4,1);
      lcd.print("LEVEL 1");
      delay(500);
    }
    if(level>25 && level<=30)
    {
      lcd.begin(16, 2);
      lcd.setCursor(2,0);
      lcd.print("CONSUMPTION");
      lcd.setCursor(4,1);
      lcd.print("LEVEL 2");
      delay(500);
    }
    if(level>30 && level<=35)
    {
      lcd.begin(16, 2);
      lcd.setCursor(2,0);
      lcd.print("CONSUMPTION");
      lcd.setCursor(4,1);
      lcd.print("LEVEL 3");
      delay(500);
    }
    if(level>35 && level<=40)
    {
      lcd.begin(16, 2);
      lcd.setCursor(2,0);
      lcd.print("CONSUMPTION");
      lcd.setCursor(4,1);
      lcd.print("LEVEL 4");
      delay(500);
    }
    if(level>40 && level<=45)
    {
      lcd.begin(16, 2);
      lcd.setCursor(2,0);
      lcd.print("CONSUMPTION");
      lcd.setCursor(4,1);
      lcd.print("LEVEL 5");
      delay(500);
    }
    if(level>45 && level<=50)
    {
      lcd.begin(16, 2);
      lcd.setCursor(2,0);
      lcd.print("CONSUMPTION");
      lcd.setCursor(4,1);
      lcd.print("LEVEL 6");
      delay(500);
    }
    if(level>50 && level<=55)
    {
      lcd.begin(16, 2);
      lcd.setCursor(2,0);
      lcd.print("CONSUMPTION");
      lcd.setCursor(4,1);
      lcd.print("LEVEL 7");
      delay(500);
    }
    if(level>55 && level<=65)
    {
      lcd.begin(16, 2);
      lcd.setCursor(2,0);
      lcd.print("CONSUMPTION");
      lcd.setCursor(4,1);
      lcd.print("LEVEL 8");
      delay(500);
    }
    if(level>65 && level<=80)
    {
      lcd.begin(16, 2);
      lcd.setCursor(2,0);
      lcd.print("CONSUMPTION");
      lcd.setCursor(4,1);
      lcd.print("LEVEL 9");
      delay(500);
    }
    if(level>=80)
    {
      lcd.begin(16, 2);
      lcd.setCursor(2,0);
      lcd.print("CONSUMPTION");
      lcd.setCursor(4,1);
      lcd.print("LEVEL 10");
      delay(500);
    }
  }
  //when kiosk is not in use or person is more than 30 cm from it
  else
  {
    lcd.begin(16,2);//no message is displayed on LCD
    digitalWrite(13,LOW);//white LEDs are OFF
    digitalWrite(6,LOW);//green LED is OFF
    noTone(5);//buzzer does not produce sound
  }
}
