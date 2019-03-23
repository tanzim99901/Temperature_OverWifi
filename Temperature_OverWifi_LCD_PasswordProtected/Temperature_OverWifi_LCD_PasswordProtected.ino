/*
  //    ----------------------------------------------------    //
  (INSTALL OneWire library beforehand)
  https://github.com/PaulStoffregen/OneWire

  Temperature sensor ORANGE = VCC
  Temperature sensor BLACK = GND
  Temperature sensor YELLOW = Signal

  //    ----------------------------------------------------    //
*/

#include <Wire.h>
#include <Keypad.h>
#include "SoftwareSerial.h"
#include <OneWire.h>
#include <LCD.h>
#include <LiquidCrystal_SR.h>
#include <LiquidCrystal.h>
LiquidCrystal_SR lcd(12, 13, 8);
//  DATA CLOCK LATCH

//SH_CP->CLOCK->13
//ST_CP->LATCH->8
//DS->DATA->12

const byte numRows = 4; //number of rows on the keypad
const byte numCols = 4; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {31, 33, 35, 37}; //Rows 0 to 3
byte colPins[numCols] = {39, 41, 43, 45}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

char* correct = "A1234";    // the correct password
int currentPosition = 0;
int i = 0;
boolean disp = 0;
boolean wrong = 0;
boolean access = 0;

String ssid = "Zeus";   // your network SSID

String password = "google123456";   // your network password

SoftwareSerial esp(62, 63);// (RX of Arduino, TX of Arduino)

String data;

String server = "tanzim99901.atwebpages.com"; // host website

String uri = "/esp8266.php";// php file to parse the values

// Indicator LEDs
int whitepin = 23;
int bluepin = 25;
int redpin = 27;
int greenpin = 29;

byte dat [5];
int DS18S20_Pin = 53; // Temperature Sensor Signal pin on Arduino digital pin 53

String temp , hum, led;
boolean connection = 0;
float threshold = 30.00; //Threshold temperature
boolean temp_warn = 0;
boolean received = 0;

OneWire ds(DS18S20_Pin);    // create Temperature sensor object

void setup()
{
  pinMode (whitepin, OUTPUT);
  pinMode (bluepin, OUTPUT);
  pinMode (redpin, OUTPUT);

  digitalWrite(whitepin, LOW);
  digitalWrite(bluepin, LOW);
  digitalWrite(redpin, LOW);\
  
  Serial.begin(9600);
  Wire.begin();
  esp.begin(9600);
  delay(1000);
  digitalWrite(whitepin, HIGH);
  delay(100);
  digitalWrite(whitepin, LOW);
  reset();    // reset wifi module

  connectWifi();    // connect to wifi network
  Serial.println("DONE CONNECTION!");

  // wait for password
  LCD_password();
  while (!access) check_password();
  Serial.println("WELCOME");
  delay(1000);
  
  LCD_setup();
}

void loop ()
{
  main_run();
}





