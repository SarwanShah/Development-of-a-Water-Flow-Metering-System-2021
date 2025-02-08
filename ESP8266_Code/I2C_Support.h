#include <Arduino.h>
#include <Wire.h>
#include "Global.h"
#include "Packet.h"
#include "Storage.h"

Storage store;
Packet flow;

void InitI2C(){
    Serial.print("Starting I2C... ");
    Wire.begin(0, 2, 10);        // join i2c bus (address optional for master)
    Wire.setClockStretchLimit(15000);
    Serial.println("[DONE]... ");

    Serial.print("Checking for Atmega328p...");
    if (i2cCheck(8)){      i2cStatus = true;  Serial.println("[DONE]");   }
    else{ i2cStatus = false; Serial.println("[No Device Found]"); }
}


void requestData(){
    while(!transmissionComplete){
    Wire.requestFrom(8, 17);    // request 6 bytes from slave device #8
    while (Wire.available()) { // slave may send less than requested
      I2C_readAnything(flowrate);
      I2C_readAnything(totalizedFlow);
      I2C_readAnything(tstamp);
      I2C_readAnything(battery);
      I2C_readAnything(transmissionComplete);
      flow.flowrate = flowrate;
      flow.totalizedFlow = totalizedFlow;
      flow.tstamp = tstamp;
      flow.battery = battery;
      if (!store.isQueueFull()){  store.enQueue(flow); }
    }
    dataPointsRecieved++;
  }  
  transmissionComplete = false;

  if (updateDAQ){
    sendUpdate();
    updateDAQ = false;
  }
}


void randomData(){
   for (int i = 1; i <= round(transmissionInterval/1000); i++){
     flow.flowrate = random(400, 550)/100.0;
     flow.totalizedFlow = 4;
     flow.tstamp = unixTime+i;
     flow.battery = random(350, 420)/100.0;
     if (!store.isQueueFull()){  store.enQueue(flow); }
   }
   unixTime = getTime();
    
    if (updateDAQ){
      sendUpdate();
      updateDAQ = false;
    }
}


void sendUpdate(){
  Serial.println("I2C: Sending Update");
  //timeDelay = millis();
  unixTime = getTime();
  Wire.beginTransmission(8);
  //timeDelay = (int)round((millis() - timeDelay)/1000.0);
  I2C_writeAnything(unixTime);
  I2C_writeAnything(measurementInterval);
  I2C_writeAnything(flowConstant);
  Wire.endTransmission(8);
  Serial.println("I2C: Sent Update!");
}

String getData(){
  flow = store.deQueue();
  String dataA = mac;
  String dataB = String(flow.tstamp);
  String dataC = String(flow.flowrate);
  String dataD = String(flow.totalizedFlow);
  String dataE = String(flow.battery); 
  String dataF = ipAddress;
  while (!store.isQueueEmpty()){
    flow = store.deQueue();
    dataA = dataA + "," + mac;
    dataB = dataB + "," + String(flow.tstamp);
    dataC = dataC + "," + String(flow.flowrate);
    dataD = dataD + "," + String(flow.totalizedFlow);
    dataE = dataE + "," + String(flow.battery); 
    dataF = dataF + "," + ipAddress;
  }
  return "A=" + dataA + "&B=" + dataB + "&C=" + dataC + "&D=" + dataD + "&E=" + dataE + "&F=" + dataF;
}



bool i2cCheck(uint8_t address){
    Wire.beginTransmission(address);
    uint8_t error = Wire.endTransmission(address);
    return error == 0;
}


template <typename T> unsigned int I2C_writeAnything (const T& value)
  {
  Wire.write((byte *) &value, sizeof (value));
  return sizeof (value);
  }  // end of I2C_writeAnything

template <typename T> unsigned int I2C_readAnything(T& value)
  {
    byte * p = (byte*) &value;
    unsigned int i;
    for (i = 0; i < sizeof value; i++)
          *p++ = Wire.read();
    return i;
  }  // end of I2C_readAnything
