#include "Global.h"
#include <WiFiClientSecure.h>
#include <ESP8266WebServer.h>   // Include the WebServer library

WiFiClientSecure client;
ESP8266WebServer server(80);    // Create a webserver object that listens for HTTP request on port 80


void sendToGoogle(String data){
  if (wifiStatus){
  Serial.print("Sending Data to Google...");
   client.setInsecure();
   uint8_t attempts = 0;
   while (!client.connect(host, httpsPort) && attempts <= 50) { delay(100);  googleStatus = false; attempts++;}
   if (attempts > 50) {googleFails++; return;}

   
   if (client.verify(fingerprint, host)) {     } 
   else {   Serial.println("certificate doesn't match");   }

   String url = "/macros/s/" + GAS_ID + "/exec?" + data; 
   //Serial.println(url);

   client.print(String("GET ") + url + " HTTP/1.1\r\n" +
        "Host: " + host + "\r\n" +
        "User-Agent: BuildFailureDetectorESP8266\r\n" +
        "Connection: close\r\n\r\n");

   String line = "";
   while (client.connected()) {
     line = client.readStringUntil('\n');
     if (line == "\r") {   break; }
    }    

   googleStatus = true;
   Serial.println("[DONE]!");
  }
}



void handleRoot() {                          // When URI / is requested, send a web page with a button to toggle the LED
  server.send(200, "text/html",\ 
  "<h1> Send updates to device: </h1></br>"
  "<form action=\"/login\" method=\"POST\"> <input type=\"transmissionInterval\" name=\"transmissionInterval\" placeholder=\"Transmission Interval (seconds)\"> </br>"
  "<input type=\"measurementInterval\" name=\"measurementInterval\" placeholder=\"Measurement Interval (seconds)\"></br>" 
  "<input type=\"flowConstant\" name=\"flowConstant\" placeholder=\"Flow Constant\"></br>" 
  "<input type=\"submit\" value=\"Update\"> </br>"
  "<p1> Device MAC: " + String(mac) + "</p1></br>"
  "<p1> I2C Status: " + String(i2cStatus) + "</p1></br>" 
  "<p1> Google Status: " + String(googleStatus) + "</p1></br>" 
  "<p1> # I2C Disconnections: " + String(i2cFails) + "</p1></br>"
  "<p1> # Google Disconnections: " + String(googleFails) + "</p1></br>"
  "<p1> # WiFi Disconnections: " + String(wifiFails) + "</p1></br>"
  "<p1> # Data Points Gathered: " + String(dataPointsRecieved) + "</p1>");
}

void handleLogin() {                         // If a POST request is made to URI /login
  if( ! server.hasArg("flowConstant") || ! server.hasArg("transmissionInterval") || ! server.hasArg("measurementInterval") 
      || server.arg("flowConstant") == NULL || server.arg("transmissionInterval") == NULL || server.arg("measurementInterval") == NULL ) { // If the POST request doesn't have flowConstant and transmissionInterval
    server.send(400, "text/plain", "400: Invalid Request");         // The request is invalid, so send HTTP status 400
    return;
  }
  else{
      transmissionInterval = (server.arg("transmissionInterval")).toInt()*1000;
      flowConstant = (server.arg("flowConstant")).toFloat();
      measurementInterval = (server.arg("measurementInterval")).toInt()*1000;
      updateDAQ = true;
      server.send(200, "text/html", "<h1> Updated values to:  " + server.arg("transmissionInterval") + ", " + server.arg("measurementInterval") + ", " + server.arg("flowConstant") + " respectively! </h1>");
  }
  Serial.print(transmissionInterval);
  Serial.print(" | ");
  Serial.print(measurementInterval);
  Serial.print(" | ");
  Serial.println(flowConstant);
}

void handleNotFound(){
  server.send(404, "text/plain", "404: Not found"); // Send HTTP status 404 (Not Found) when there's no handler for the URI in the request
}
