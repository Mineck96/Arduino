#include <SimpleDHT.h>

int pinDHT11 = 2;
int tempPin = A0; // the output pin of DHT11

int temp;
int miniTemp = 27;  // the temperature to start the fan
int fan = 11; // the pin where fan is


int readTemp() {  // get the temperature and convert it to celsius
  temp = analogRead(tempPin);
  return temp * 0.48828125;
}

void setup() {

  Serial.println("Fan control using DHT11 Sensor\n\n");
  delay(1000);//Wait before accessing Sensor

  pinMode(fan, OUTPUT);
  digitalWrite(fan, LOW);
  Serial.begin(9600);
}


void loop() {
  // start working...
  temp = readTemp();  //get the temperature

  if (temp  < miniTemp) { // if temp is lower than minimum temp

    digitalWrite(fan, LOW);
  }
  else {
    digitalWrite(fan, HIGH);  // turn on fan
  }
}
