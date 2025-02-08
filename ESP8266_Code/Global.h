// -------------------------------------------------- Google Sheet's Setup ----------------------------------------------------------------- //

extern const char* host;
extern const int httpsPort;
extern const char* fingerprint;
extern String GAS_ID;  // Replace by your GAS service id


// -------------------------------------------------- Function Definitions  ----------------------------------------------------------------- //


extern void InitWiFi();
extern unsigned long getTime();
extern void getMACAddress();
extern void getIPAddress();

extern void InitI2C();
extern void requestData();
extern void sendUpdate();
extern bool i2cCheck(uint8_t address);
template <typename T> extern unsigned int I2C_readAnything(T& value);
template <typename T> extern unsigned int I2C_writeAnything (const T& value);

extern void sendToGoogle(String data);
extern String getData();
extern void handleRoot();             
extern void handleLogin();
extern void handleNotFound();


// -------------------------------------------------- Initialize Variables  ----------------------------------------------------------------- //

extern const char* ssid;
extern const char* password;

extern unsigned long timeElapsed;
extern unsigned long unixTime;
extern unsigned long timeDelay;
extern unsigned long transmissionInterval;

extern unsigned long tstamp;
extern float flowrate;
extern float battery;
extern float totalizedFlow;

extern bool transmissionComplete;
extern bool i2cStatus;
extern bool googleStatus;
extern bool wifiStatus;

extern bool updateDAQ;
extern unsigned long dataPointsRecieved;
extern uint8_t i2cFails;
extern uint8_t googleFails;
extern uint8_t wifiFails;
        

        
extern float flowConstant;
extern unsigned long measurementInterval;

extern String mac;
extern String ipAddress;

//------------------------------------------------------------------------------------------------------------------------------------------//
