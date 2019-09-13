#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <String.h>
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
void Send_data()   //to send data to thingspeak channel
{
  mySerial.println("AT");
  delay(1000);

  mySerial.println("AT+CPIN?");
  delay(1000);

  mySerial.println("AT+CREG?");
  delay(1000);

  mySerial.println("AT+CGATT?");
  delay(1000);

  mySerial.println("AT+CIPSHUT");
  delay(1000);

  mySerial.println("AT+CIPSTATUS");
  delay(2000);

  mySerial.println("AT+CIPMUX=0");
  delay(2000);

  ShowSerialData();

  mySerial.println("AT+CSTT=\"www\"");//start task and setting the APN,
  delay(1000);

  ShowSerialData();

  mySerial.println("AT+CIICR");//bring up wireless connection
  delay(3000);

  ShowSerialData();

  mySerial.println("AT+CIFSR");//get local IP adress
  delay(2000);

  ShowSerialData();

  mySerial.println("AT+CIPSPRT=0");
  delay(3000);

  ShowSerialData();

  mySerial.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");//start up the connection
  delay(6000);

  ShowSerialData();

  mySerial.println("AT+CIPSEND");//begin send data to remote server
  delay(4000);
  ShowSerialData();

  String str = "GET https://api.thingspeak.com/update?api_key=SALKQM2665XVB256&field1=" + String(temp) + "&field2=" + String(turbid);

  mySerial.println(str);//begin send data to remote server
  delay(4000);
  ShowSerialData();

  mySerial.println((char)26);//sending
  delay(5000);//waitting for reply, the time is base on the condition of internet
  mySerial.println();

  ShowSerialData();

  mySerial.println("AT+CIPSHUT");//close the connection
  delay(100);
  ShowSerialData();
}
