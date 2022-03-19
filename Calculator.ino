#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

// keypad
const int r1 = 7;
const int r2 = 8;
const int r3 = 9;
const int r4 = 10;

const int c1 = A0;
const int c2 = A1;
const int c3 = A2;
const int c4 = A3;

int num = 0;
char symbol;


// Calculator
int num1 = 0;
int num2 = 0;
int operation;
int result;
int selector = 0;




void setup() {
lcd.begin(16, 2);
pinMode(switchPin, INPUT);
lcd.print("Welcome to calc");
delay (2000);
lcd.clear();

//Keypad
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  pinMode(r4,OUTPUT);

  pinMode(c1,INPUT_PULLUP);  
  pinMode(c2,INPUT_PULLUP);
  pinMode(c3,INPUT_PULLUP);
  pinMode(c4,INPUT_PULLUP);
  Serial.begin(9600);
}


void loop() {
//Analysis of Row 1
  digitalWrite(r1,LOW);
  if (digitalRead(c1) == LOW) {num = 1;lcd.print(num);Serial.print(num); selector = 0;}     
  if (digitalRead(c2) == LOW) {num = 2;lcd.print(num);Serial.print(num); selector = 0;} 
  if (digitalRead(c3) == LOW) {num = 3;lcd.print(num);Serial.print(num); selector = 0;} 
  if (digitalRead(c4) == LOW) {symbol = '+' ;lcd.print("+");Serial.println(symbol);} 
  digitalWrite(r1,HIGH);

//Analysis of Row 2
  digitalWrite(r2,LOW);
  if (digitalRead(c1) == LOW) {num = 4; lcd.print(num);Serial.print(num); selector = 0;}     
  if (digitalRead(c2) == LOW) {num = 5; lcd.print(num);Serial.print(num); selector = 0;} 
  if (digitalRead(c3) == LOW) {num = 6; lcd.print(num);Serial.print(num); selector = 0;} 
  if (digitalRead(c4) == LOW) {symbol = '-' ;lcd.print("-");Serial.println(symbol);} 
  digitalWrite(r2,HIGH);

//Analysis of Row3
  digitalWrite(r3,LOW);
  if (digitalRead(c1) == LOW) {num = 7; lcd.print(num);Serial.print(num); selector = 0;}     
  if (digitalRead(c2) == LOW) {num = 8; lcd.print(num);Serial.print(num); selector = 0;} 
  if (digitalRead(c3) == LOW) {num = 9; lcd.print(num);Serial.print(num); selector = 0;} 
  if (digitalRead(c4) == LOW) {symbol = '*' ;lcd.print("*");Serial.println(symbol);} 
  digitalWrite(r3,HIGH);

//Analysis of Row 4
  digitalWrite(r4,LOW);
  if (digitalRead(c1) == LOW) {lcd.clear(); num1 = 0; num2 = 0; result = 0; symbol = 0;}     
  if (digitalRead(c2) == LOW) {num = 0; lcd.print(num);Serial.print(num); selector = 0;} 
  if (digitalRead(c3) == LOW) {symbol = '=' ;lcd.print("=");Serial.println(symbol);} 
  if (digitalRead(c4) == LOW) {symbol = '/' ;lcd.print("/");Serial.println(symbol);} 
  digitalWrite(r4,HIGH);

  delay(300);
  


//Calculator
 //storing values

if (selector == 0){
          if (num == 0){if (num1 == 0){num1 = 0;}else num1 = (num1*10) +0 ;}
          if (num == 1){if (num1 == 0){num1 = 1;}else num1 = (num1*10) + 1;}
          if (num == 2){if (num1 == 0){num1 = 2;}else num1 = (num1*10) + 2;}
          if (num == 3){if (num1 == 0){num1 = 3;}else num1 = (num1*10) + 3;}
          if (num == 4){if (num1 == 0){num1 = 4;}else num1 = (num1*10) + 4;}
          if (num == 5){if (num1 == 0){num1 = 5;}else num1 = (num1*10) + 5;}
          if (num == 6){if (num1 == 0){num1 = 6;}else num1 = (num1*10) + 6;}
          if (num == 7){if (num1 == 0){num1 = 7;}else num1 = (num1*10) + 7;}
          if (num == 8){if (num1 == 0){num1 = 8;}else num1 = (num1*10) + 8;}
          if (num == 9){if (num1 == 0){num1 = 9;}else num1 = (num1*10) + 9;}         
}
      

//finding the operation 
selector = 1;
  if (symbol == '+'){operation = "1"; num2 = num1; symbol = 0; num1 = 0;}
  if (symbol == '-'){operation = "2"; num2 = num1; symbol = 0; num1 = 0;}
  if (symbol == '*'){operation = "3"; num2 = num1; symbol = 0; num1 = 0;} 
  if (symbol == '/'){operation = "4"; num2 = num1; symbol = 0; num1 = 0;} 

if (symbol == '=') {
  if (operation == "1"){
  lcd.setCursor(0,1);
  result = num1 + num2;
  lcd.print(result);
  Serial.println(result);
  Serial.println(num1);
  Serial.println(num2);
  symbol = '0';
  operation = "0";
  }
  
  if (operation == "2"){
  lcd.setCursor(0,1);
  result = num2 - num1;
  lcd.print(result);
  Serial.println(result);
  Serial.println(num1);
  Serial.println(num2);
  symbol = '0';
  operation = "0";
  }

  if (operation == "3"){
  lcd.setCursor(0,1);
  result = num1 * num2;
  lcd.print(result);
  Serial.println(result);
  Serial.println(num1);
  Serial.println(num2);
  symbol = '0';  
  operation = "0";
  }
  
  if (operation == "4"){
  lcd.setCursor(0,1);
  result = num2 / num1;
  lcd.print(result);
  Serial.println(result);
  Serial.println(num1);
  Serial.println(num2);
  symbol = '0';  
  operation = "0";
  }
}
}
