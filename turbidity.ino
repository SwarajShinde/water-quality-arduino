void setup() {
  Serial.begin(9600); //Baud rate: 9600
}
void loop() {
  float ntu;
  int sensorValue = analogRead(A0);// read the input on analog pin 0:
  float volt = sensorValue * (5.0 / 1024.0);// Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  for(int i=0; i<50; i++)
    {
        volt += ((float)analogRead(sensorValue)/1023)*5;
    }
    volt = volt/50;
  if(volt < 2.5){
      ntu = 3000;
    }else{
      ntu = -1120.4*square(volt)+5742.3*volt-1759.4; 
    }
  Serial.println(volt);
  Serial.println(ntu); // print out the value you read: value of voltage of clear water is 4.8 .
  
  delay(500);
}
