#include <DHT.h>

const int BIA = 8;
const int BIB = 7;
const int SW_pin = 2;
const int X_pin = 0;
const int Y_pin = 1;
const int temperatura = 4;
DHT dht(temperatura,DHT11);
void setup() {
  pinMode(SW_pin,INPUT);
  digitalWrite(SW_pin,HIGH);
  pinMode(BIA,OUTPUT);
  pinMode(BIB,OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temper = dht.readTemperature();
  if(temper > 29.5){
    Serial.print(temper);
    Serial.print("\n");
    motorB('L');
    delay(2000);
  }
  else{
    if(analogRead(X_pin) > 700){
    Serial.print("-Stanga");
    Serial.print("\n");
    motorB('L');
    delay(2000);
    }
    else{
      if(analogRead(X_pin) < 300){
        Serial.print("-Dreapta");
        Serial.print("\n");  
        motorB('R');
        delay(2000);
      }
      else{
        Serial.print("-Stop");
        Serial.print("\n");
        motorB('0');
        delay(2000);
      }
    }
  }
}
void motorB(char c){
  if(c == 'R'){
    digitalWrite(BIA,LOW);
    digitalWrite(BIB,HIGH);
  }
  else if (c == 'L'){
    digitalWrite(BIA,HIGH);
    digitalWrite(BIB,LOW);
  }
  else{
    digitalWrite(BIA,LOW);
    digitalWrite(BIB,LOW);
  }
}