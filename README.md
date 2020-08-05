# Police Safety
Movable kiosk containing alcohol detector to ensure social distancing while checking level of alcohol consumed

## Project design:
1. A movable kiosk is placed near police van to check drunken driving. When a person appraoches the kiosk, white lights turn ON
2. LCD displays instructions to be followed throughout
3. When the person is less than 3cms from kiosk, grren lights turns ON followed by a beep sound. The person should blow into alcohol detector indicated by the 'Blow Here' sign
4. A series of lights indicate alcohol intensity and LCD displays the level of consumption on a level of 0-10

## Working:
1. When a person approaches kiosk, an ultrasonic sensor detects the distance between person and kiosk and if the distance is measured to be less than 30cms then 'white' lights are turned ON and the person is asked to step closer by a message displayed in LCD
2. When the person is less than 3cms from the kiosk which is measured by ultrasonic sensor, 'green' light turns ON and LCD displays a message that when you hear a beep sound (produced by a buzzer), blow into disposable mouthpiece indicated by a 'blow here' sign
3. A series of 'red' lights turn ON depending on alcohol concentration level and LCD displays level of consumption on a scale of 0-10

### Libraries used:
The library used in this project is 'Liquid Crystal'
>This library allows an Arduino board to control LiquidCrystals displays (LCDs)

Guidelines to install this library:
1. Open arduino IDE and click 'Sketch'>'Include Library'>'Manage Libraries'
2. You will find list of libraries already installed or ready for installation
3. Search "LiquidCrystal"
4. Select the version that you desrire and click 'install'
5. Wait for IDE to install the new library

To use this library:
#include<LiquidCrystal.h>

For more information about this library please visit- http://www.arduino.cc/en/Reference/LiquidCrystal


#### Tinkercad simulation link:
https://www.tinkercad.com/things/9xRdnZGhjwt-police-safety/editel?sharecode=XE7V7jbO2b_iEP273OEn3a4-y3UHAjKeo30WgE-hJsQ
