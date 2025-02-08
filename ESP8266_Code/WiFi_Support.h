#include "Global.h"
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <ESP8266WiFi.h>

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

//Fixed IP address to be used on Habib's Network
//IPAddress ipAdd(10,25,0,1);
//IPAddress dns(8,8,8,8);
//IPAddress gateway(10,25,0,25);
//IPAddress subnet(255,255,248,0);

void InitWiFi(){
  Serial.print("Connecting to WiFi...  ");
  WiFi.mode(WIFI_STA);
  //WiFi.config(ipAdd, dns, gateway, subnet);    //Uncomment this line, when fixed/static IP being used on Habib network
  WiFi.begin(ssid, password);

  uint8_t attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts <= 30) {    delay(500);    attempts++;  }    
  if (attempts > 30) {wifiFails++; return;} 
  
  Serial.println("[DONE]");

  Serial.print("Starting HTTP Server... ");
  server.on("/", HTTP_GET, handleRoot);        // Call the 'handleRoot' function when a client requests URI "/"
  server.on("/login", HTTP_POST, handleLogin); // Call the 'handleLogin' function when a POST request is made to URI "/login"
  server.onNotFound(handleNotFound);           // When a client requests an unknown URI (i.e. something other than "/"), call function "handleNotFound"

  server.begin();                            // Actually start the server
  wifiStatus = true;
  Serial.println("[Done]");
}


unsigned long getTime(){
  timeClient.update();
  unsigned long now = timeClient.getEpochTime();
  return now;
}


void getMACAddress(){
    Serial.print("Retrieving MAC Address... ");
    unsigned char temp[6];
    WiFi.macAddress(temp);
    for (int i = 0; i < 6; ++i) {
      mac += String(temp[i], 16);
      if (i < 5){ mac += ':'; } 
    }       
    Serial.println("[DONE]");
}

void getIPAddress(){
    Serial.print("Retrieving IP Address... ");
    IPAddress ip = WiFi.localIP();
    ipAddress = String(ip[0]) + String(".") + String(ip[1]) + String(".") + String(ip[2]) + String(".") + String(ip[3]);
    Serial.println("[DONE]");
}
