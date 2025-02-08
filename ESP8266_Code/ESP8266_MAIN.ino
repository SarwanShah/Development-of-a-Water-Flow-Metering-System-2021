#include "I2C_Support.h"
#include "Http_Support.h"
#include "WiFi_Support.h"


// -------------------------------------------------- Google Sheet's Setup ----------------------------------------------------------------- //

const char* host = "script.google.com";
const int httpsPort = 443;
const char* fingerprint = "46 B2 C3 44 9C 59 09 8B 01 B6 F8 BD 4C FB 00 74 91 2F EF F6";
String GAS_ID = "AKfycbz61YrIRc7bbjTzWvuqwNgtuvjHlYY-hur7po5xZyzckkITpsEv";  // Replace by your GAS service id

// -------------------------------------------------- Function Definitions  ----------------------------------------------------------------- //

void InitWiFi();
unsigned long getTime();
void getMACAddress();
void getIPAddress();

void InitI2C();
void requestData();
void sendUpdate();
bool i2cCheck(uint8_t address);
template <typename T> unsigned int I2C_readAnything(T& value);
template <typename T> unsigned int I2C_writeAnything (const T& value);

void sendToGoogle(String data);
String getData();
void handleRoot();             
void handleLogin();
void handleNotFound();


// -------------------------------------------------- Initialize Variables  ----------------------------------------------------------------- //

const char* ssid = "HU-Guest14";
const char* password = "HU_GUEST14";

unsigned long timeElapsed = 0;
unsigned long unixTime = 0;
unsigned long timeDelay = 0;
unsigned long transmissionInterval = 30000;

unsigned long tstamp = 0;
float flowrate = 0;
float battery = 0;
float totalizedFlow = 0;

bool transmissionComplete = false;

bool i2cStatus = false;
bool googleStatus = false;
bool wifiStatus = false;

bool updateDAQ = false;


unsigned long dataPointsRecieved = 0;
uint8_t i2cFails = 0;
uint8_t googleFails = 0;
uint8_t wifiFails = 0;
        
float flowConstant = 4.18;
unsigned long measurementInterval = 1000;

String mac = "";
String ipAddress = "";

//------------------------------------------------------------------------------------------------------------------------------------------//



void setup() {
  Serial.begin(9600);  // start serial for output
  delay(5000);

  InitWiFi();
  InitI2C();
  getIPAddress();
  getMACAddress();

  Serial.print("Device MAC: ");
  Serial.println(mac);
  Serial.print("Server Address: ");
  Serial.println(ipAddress);
  
  sendUpdate();
  timeElapsed = millis();
}

void loop() {  
  if (WiFi.status() != WL_CONNECTED){     
    InitWiFi();   
    if (wifiStatus) {sendUpdate();}
  }

  if (millis() - timeElapsed >= transmissionInterval ) { 
    if (i2cCheck(8)){
      timeElapsed = millis();
      requestData();
      Serial.println("Recieved Data");  
      i2cStatus = true;
    }
    else {
       if (i2cStatus) {i2cFails++;}
       i2cStatus = false;  
       randomData();
       timeElapsed = millis();         
    }
  }
  
  if (!store.isQueueEmpty()){
    sendToGoogle(getData());
  }
  
  server.handleClient();                     // Listen for HTTP requests from clients
}
