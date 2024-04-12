
#include <LiquidCrystal.h>
#include <EasyMFRC522.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
const int array_size = 1000;
#define MAX_KEY_SIZE 100
#define BLOCK 1 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
EasyMFRC522 rfidReader(7, 8);
void setup() {
  analogWrite(6, 75);
  lcd.begin(16, 2);
  rfidReader.init();
  pinMode(9, INPUT);
}
void loop() {
  lcd.clear();
  while (Serial.available() == 0){
  Serial.println("Scan your key");
  }
  bool success;
  do {
    success = rfidReader.detectTag();    
    delay(50); //0.05s
  } while (!success);
  lcd.clear();
  lcd.print("Key Detected!");
  int RFID_key;
  int keyBuffer[MAX_KEY_SIZE];
  RFID_key = rfidReader.readFile(BLOCK, "mylabel", (byte*)keyBuffer, MAX_KEY_SIZE);
  keyBuffer[MAX_KEY_SIZE-1] = 0;
  srand(time(NULL));
  double x_array[array_size];
  int maximum = 2;
  int minimum = -2;
  int difference = maximum - minimum;
  int array_num = (rand() % array_size + 1); 
  for (int i = 0; i < (array_size); i++){
    x_array[i] = minimum + (difference/array_size);
  }
  float x = x_array[array_num];
  lcd.print("Num: " + char(array_num));
  float y = sqrt(pow(x,3) - 3*x + 3);
  float distance = sqrt(pow(x,2) + pow(y,2));
  int key_a = RFID_key;
  float key_one = key_a * distance;
  lcd.setCursor(0,2);
  lcd.print("Key:" + char(key_one));
  do{
    delay(5);
  }
  while (digitalRead(9) == LOW);
}
