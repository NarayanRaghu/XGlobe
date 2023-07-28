#include <Keypad.h>

#include <Servo.h>

 

Servo xServo;  // create servo object to control a servo

Servo yServo;

int servoXPos = 0;    // variable to store the servo position

int servoYPos = 0;

int curXPos = 0;

int pos = 0;

// define the symbols on the buttons of the keypad

char keys[4][4] = {

 {'1', '2', '3', 'A'},

 {'4', '5', '6', 'B'},

 {'7', '8', '9', 'C'},

 {'*', '0', '#', 'D'}

};

 

byte rowPins[4] = {11, 10, 9, 8}; // connect to the row pinouts of the keypad

byte colPins[4] = {7, 6, 5, 4}; // connect to the column pinouts of the keypad

// initialize an instance of class Keypad

Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

void setup() {

 Serial.begin(9600); // Initialize the serial port and set the baud rate to 9600

 xServo.attach(12);  // attaches the servo on pin 9 to the servo object

 yServo.attach(13);

}

void loop() {

 // Get the character input

 char keyPressed = myKeypad.getKey();

 // If there is a character input, sent it to the serial port

 if (keyPressed) {

   curXPos = servoXPos;

   Serial.println(keyPressed);

   switch(keyPressed) {

     case '1': servoXPos = 0;//Oceania

     servoYPos = 25;

     break;

     case '2': servoXPos = 135;//Asia

     servoYPos = 100;

     break;

     case '3': servoXPos = 110;//Africa

     servoYPos = 90;

     break;

     case '4': servoXPos = 110;//Europe

     servoYPos = 150;

     break;

     case '5': servoXPos = 50;//North America

     servoYPos = 125;

     break;

     case '6': servoXPos = 70;//South America

     servoYPos = 60;

     break;

     case '7': servoXPos = 10;//Antarctica

     servoYPos = 0;

     break;

     case '8': servoXPos = 10;//New Zealand

     servoYPos = 10;

     break;

     case '9': servoXPos = 0;//Arctic Ocean

     servoYPos = 180;

     break;

     case '0': servoXPos = 0;//Recalibrate

     servoYPos = 10;

     break;

     case 'A': servoXPos = 75;//North Atlantic

     servoYPos = 105;

     break;

     case 'B': servoXPos = 90;//South Atlantic

     servoYPos = 87;

     break;

     case 'C': servoXPos = 165;//North Pacific

     servoYPos = 125;

     break;

     case 'D': servoXPos = 175;//South Pacific

     servoYPos = 30;

     break;

     case '*': servoXPos = 135;//Indian Ocean

     servoYPos = 65;

     break;

     case '#': servoXPos = 15;//Southern Ocean

     servoYPos = 30;

     break;

     default: servoXPos = 0;

     servoYPos = 20;

     break;

      }

  if(curXPos<servoXPos)

  {

    for (pos = curXPos; pos <= servoXPos; pos += 1) { // goes up in graduations 1 degree

        // in steps of 1 degree

        xServo.write(pos);              // tell servo to go to position in variable 'pos'

        delay(15);                       // waits 15ms for the servo to reach the position

      }

  }

  else

  {

    for (pos = curXPos; pos >= servoXPos; pos -= 1) { // goes down in graduations of 1 degree

        // in steps of 1 degree

        xServo.write(pos);              // tell servo to go to position in variable 'pos'

        delay(15);                       // waits 15ms for the servo to reach the position

      }

  }

 

   yServo.write(servoYPos);

 

 }

}
