#include "DHT.h"
#define DHTTYPE DHT11
#define dht_pin D3
DHT dht(dht_pin,DHTTYPE);

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

    // Dapetin token
char auth[] = "ibiPje43CXExO4P9kywtAPMyc1xzMbs-";
    // id dan password internet 
char ssid[] = "antique";
char pass[] = "bismillah";

void setup(){
  Serial.begin(9600);
  dht.begin();
  
  //kalo pake serangkota jangan lupa ganti jadi
  //Blynk.begin(auth, ssid, pass, "iot.serangkota.go.id", 8080);
  //Blynk.begin(auth, ssid, pass);
  Blynk.begin(auth, ssid, pass);
}

void loop(){
  float s = dht.readTemperature();
  float h = dht.readHumidity();
  Blynk.run();
  Blynk.virtualWrite(V0, s);
  Blynk.virtualWrite(V1, h);
  
}
