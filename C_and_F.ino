#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>
SoftwareSerial mySerial(9, 10);

#define ONE_WIRE_BUS 8

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);


float Celsius = 0;
float Fahrenheit = 0;

void setup() {
  sensors.begin();
  mySerial.begin(9600);
  Serial.begin(9600);
  delay(500);
}

void loop() {
  sensors.requestTemperatures();

  Celsius = sensors.getTempCByIndex(0);
  Fahrenheit = sensors.toFahrenheit(Celsius);
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1024.0);

  Serial.print(Celsius);
  Serial.print(" C  ");
  Serial.print(Fahrenheit);
  Serial.println(" F");
  Serial.println(voltage);

  delay(1000);
}
