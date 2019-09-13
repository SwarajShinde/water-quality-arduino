#include <Blynk.h>

//BLYNK Boilerplate code integration with the 2 sensors is remaining
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// just change 2 lines of code//
//ie.only changing .email and .notify//
char auth[] = " uuwvKdnLoThawfKpzOZ4RRUK3kCy8LKf";

char ssid[] = "ITZSAS";
char pass[] = "d1nallol";

if(Celsius > 40){
  Blynk.email("swarajshinde20@gmail.com","ESP8266 Alert","Temprature over 40")//Blynk API call for EMAIL sending
  Blynk.notify("ESP8266 Alert - Temperature over 28")//Blynk API call for NOTIFICATION pushing
}
elif(NTU > 5){
  Blynk.email("swarajshinde20@gmail.com","ESP8266 Alert","NTU over 5")//Blynk API call for EMAIL sending
  Blynk.notify("ESP8266 Alert - NTU over 5")//Blynk API call for NOTIFICATION pushing
}
}

  

void setup()
{
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  
}

void loop()
{
  Blynk.run();
}
