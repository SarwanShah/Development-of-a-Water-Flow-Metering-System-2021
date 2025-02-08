 /* Exhaustive list for available options for Timer 2 delay, given interrupts per second is limited to uint8 
 Utilize Phase-Correct PWM Mode, TCNT counts 0 - 510
Base Time:  0.032704  TCNT2:  0 // Largest possible base time
Base Time:  6.4e-05  TCNT2:  510 // Smallest possible base time
   
Base Time:  0.0048  Total Time:  0.6  TCNT2:  436  Interrupts Per Second:  125
Base Time:  0.0048  Total Time:  1.2  TCNT2:  436  Interrupts Per Second:  250
Base Time:  0.008  Total Time:  0.2  TCNT2:  386  Interrupts Per Second:  25   //Smallest possible delay rounded the first decimal place
Base Time:  0.008  Total Time:  0.4  TCNT2:  386  Interrupts Per Second:  50
Base Time:  0.008  Total Time:  0.6  TCNT2:  386  Interrupts Per Second:  75
Base Time:  0.008  Total Time:  0.8  TCNT2:  386  Interrupts Per Second:  100
Base Time:  0.008  Total Time:  1.0  TCNT2:  386  Interrupts Per Second:  125  //Smallest possilble whole number delay in seconds, 
Base Time:  0.008  Total Time:  1.2  TCNT2:  386  Interrupts Per Second:  150
Base Time:  0.008  Total Time:  1.6  TCNT2:  386  Interrupts Per Second:  200
Base Time:  0.008  Total Time:  1.8  TCNT2:  386  Interrupts Per Second:  225
  Base Time:  0.008  Total Time:  2.0  TCNT2:  386  Interrupts Per Second:  250
  Base Time:  0.0096  Total Time:  1.2  TCNT2:  361  Interrupts Per Second:  125
  Base Time:  0.0096  Total Time:  2.4  TCNT2:  361  Interrupts Per Second:  250
  Base Time:  0.0112  Total Time:  1.4  TCNT2:  336  Interrupts Per Second:  125
  Base Time:  0.0112  Total Time:  2.8  TCNT2:  336  Interrupts Per Second:  250
  Base Time:  0.0144  Total Time:  1.8  TCNT2:  286  Interrupts Per Second:  125
Base Time:  0.0144  Total Time:  3.6  TCNT2:  286  Interrupts Per Second:  250
Base Time:  0.016  Total Time:  0.4  TCNT2:  261  Interrupts Per Second:  25
Base Time:  0.016  Total Time:  0.8  TCNT2:  261  Interrupts Per Second:  50
Base Time:  0.016  Total Time:  1.2  TCNT2:  261  Interrupts Per Second:  75
Base Time:  0.016  Total Time:  1.6  TCNT2:  261  Interrupts Per Second:  100
Base Time:  0.016  Total Time:  2.0  TCNT2:  261  Interrupts Per Second:  125
Base Time:  0.016  Total Time:  2.4  TCNT2:  261  Interrupts Per Second:  150
Base Time:  0.016  Total Time:  3.2  TCNT2:  261  Interrupts Per Second:  200
Base Time:  0.016  Total Time:  3.6  TCNT2:  261  Interrupts Per Second:  225
Base Time:  0.016  Total Time:  4.0  TCNT2:  261  Interrupts Per Second:  250
Base Time:  0.0192  Total Time:  2.4  TCNT2:  211  Interrupts Per Second:  125
Base Time:  0.0192  Total Time:  4.8  TCNT2:  211  Interrupts Per Second:  250
Base Time:  0.0208  Total Time:  2.6  TCNT2:  186  Interrupts Per Second:  125
Base Time:  0.0208  Total Time:  5.2  TCNT2:  186  Interrupts Per Second:  250
Base Time:  0.0224  Total Time:  2.8  TCNT2:  161  Interrupts Per Second:  125
Base Time:  0.0224  Total Time:  5.6  TCNT2:  161  Interrupts Per Second:  250
Base Time:  0.024  Total Time:  0.6  TCNT2:  136  Interrupts Per Second:  25
Base Time:  0.024  Total Time:  1.2  TCNT2:  136  Interrupts Per Second:  50
Base Time:  0.024  Total Time:  1.8  TCNT2:  136  Interrupts Per Second:  75
Base Time:  0.024  Total Time:  2.4  TCNT2:  136  Interrupts Per Second:  100
Base Time:  0.024  Total Time:  3.0  TCNT2:  136  Interrupts Per Second:  125
Base Time:  0.024  Total Time:  3.6  TCNT2:  136  Interrupts Per Second:  150
Base Time:  0.024  Total Time:  4.2  TCNT2:  136  Interrupts Per Second:  175
Base Time:  0.024  Total Time:  4.8  TCNT2:  136  Interrupts Per Second:  200
Base Time:  0.024  Total Time:  5.4  TCNT2:  136  Interrupts Per Second:  225
Base Time:  0.024  Total Time:  6.0  TCNT2:  136  Interrupts Per Second:  250
Base Time:  0.0272  Total Time:  3.4  TCNT2:  86  Interrupts Per Second:  125
Base Time:  0.0272  Total Time:  6.8  TCNT2:  86  Interrupts Per Second:  250
Base Time:  0.0288  Total Time:  3.6  TCNT2:  61  Interrupts Per Second:  125
Base Time:  0.0288  Total Time:  7.2  TCNT2:  61  Interrupts Per Second:  250
Base Time:  0.0304  Total Time:  3.8  TCNT2:  36  Interrupts Per Second:  125
Base Time:  0.0304  Total Time:  7.6  TCNT2:  36  Interrupts Per Second:  250
Base Time:  0.032  Total Time:  0.8  TCNT2:  11  Interrupts Per Second:  25
Base Time:  0.032  Total Time:  1.6  TCNT2:  11  Interrupts Per Second:  50
Base Time:  0.032  Total Time:  2.4  TCNT2:  11  Interrupts Per Second:  75
Base Time:  0.032  Total Time:  3.2  TCNT2:  11  Interrupts Per Second:  100
Base Time:  0.032  Total Time:  4.0  TCNT2:  11  Interrupts Per Second:  125
Base Time:  0.032  Total Time:  4.8  TCNT2:  11  Interrupts Per Second:  150
Base Time:  0.032  Total Time:  6.4  TCNT2:  11  Interrupts Per Second:  200
Base Time:  0.032  Total Time:  7.2  TCNT2:  11  Interrupts Per Second:  225
Base Time:  0.032  Total Time:  8.0  TCNT2:  11  Interrupts Per Second:  250


Note: Multiplying the "interrupts per second" variable can provide accurate and precise delays that are some multiple of the aforementioned times. 


Largest number that can be stored on an arduino is an unsigned long, ranging from 0 to 4,294,967,295
The maximum achievable time/sampling delay, with interrupts per second set to long, is 137438952.8 seconds, rounded to the first
decimal place, and is 4294967250 seconds, rounded to a whole number. List of required settings:

Base Time:  0.032  Total Time:  137438952.0  TCNT2:  11  Interrupts Per Second:  4294967250
Base Time:  0.032  Total Time:  137438952.8  TCNT2:  11  Interrupts Per Second:  4294967275
 
*/


/* -------------------------------------------- Import Libraries ------------------------------------------------- */
#include "Packet.h"
#include "Storage.h"
#include "LowPower.h"
#include "I2C_Support.h"
#include <Wire.h>


/* 
RTClib.h:
Does not interfere with timers. Uses I2C Protocol, which utilized the CPU Clock to decide SCL frequency via Bit Rate Generator - Ref: Atmega328p Section: 21.5.2

Software Serial:
Went through its library thoroughly. It uses a funtion "tunedDelay" for timing most of its communication. The "tunedDelay" function utilizes a core AVR 
function named "_delay_loop_2", this utilizes a 16 bit counter, not a 16 bit timer, generating a delay of 262.1 milliseconds using CPU clocks with the help
of the BRNE instruction. No reference to timers was found what so ever. Furthermore, as far as interrupts are concerned. The library does utilized interrupts,
which involves enabling and disabling interrupts at SPECIFIC pins only via the PCMSKx Pin Change Interrupt registers, so timer or other interrupts are 
not effected in any way. 
*/


/*------------------------------------------- Define Pins -------------------------------------------------------*/
#define batterySense A1
#define SDA A4
#define SCL A5

/*------------------------------------------- Define Variables -------------------------------------------------------*/

// --- For timer interrupts and flow measurement ---

unsigned long measurementInterval = 1000; // Currently, 1 second. Change this to change the delay time in seconds
uint16_t measurement_interval_in_seconds = measurementInterval/1000;
uint8_t dataPointsSent = 0;


unsigned long past_time = 0;
unsigned long measurementInstance = 0;
unsigned long unixTime = 0;
unsigned long recieveTime = 0;


// --- Flow
float frequency = 0;
float volume = 0;
float voltage = 0;
float flowConstant = 4.18;



bool updateRecieved = false;
bool startDAQ = false;





/* ----------------------------------------- Initilize objects ----------------------------------------------------- */
Packet flow;
Packet auxillary;
Storage store;


/* ----------------------------------------- Declare functions ---------------------------------------------------- */
void setTimer1();


void setup() {
  pinMode(batterySense, INPUT);
  pinMode(5, INPUT_PULLUP);
  analogReference(INTERNAL);

 //Initilize Serial Communication
  Serial.begin(9600);
  
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveTime); // register event


  //Initilize Timers
  Serial.print("Timer Activation... ");
  GTCCR = (1<<TSM) | (1<<PSRASY) | (1<<PSRSYNC); // Stop all timers
  setTimer1();  
  GTCCR &= 0x00;  // Start all timers
  Serial.println("[DONE]");

  TCNT1 = 0;              //Reset timer 1
  past_time = millis();
}


//-------------------------------------------------



void loop() {  
  if (startDAQ){
    if (millis() - past_time >= measurementInterval){
      measurementInstance = millis() - past_time;
      
      if (measurementInstance > 1000) { past_time = millis()-(measurementInstance - 1000); }
      else { past_time = millis(); }

      if (updateRecieved){  unixTime =  unixTime + round((millis()-recieveTime)/1000.0);  updateRecieved = false; }
      else {   unixTime =  unixTime + round(measurementInstance/1000.0); }
      
      frequency = TCNT1/(measurement_interval_in_seconds*1.0);
      TCNT1 = 0;     
      flow.flowrate = ((frequency)/flowConstant); // It must be in  litres per min
      volume += (flow.flowrate)*(measurement_interval_in_seconds/60.0);
      flow.totalizedFlow = volume;
      flow.tstamp = unixTime;
      flow.battery = batteryLevel();
            
      if (!store.isQueueFull()){      store.enQueue(flow); }
    }   
  }
  else {
    past_time = millis();
  }
}


//------------------------------------------------

void requestMeasurement() {
     auxillary = store.deQueue();
     I2C_writeAnything(auxillary.flowrate);
     I2C_writeAnything(auxillary.totalizedFlow);
     I2C_writeAnything(auxillary.tstamp);
     I2C_writeAnything(auxillary.battery);
     I2C_writeAnything(store.isQueueEmpty());
     dataPointsSent++;
}


void receiveTime(){
  while (Wire.available()) { 
     I2C_readAnything(unixTime);
     I2C_readAnything(measurementInterval);
     I2C_readAnything(flowConstant);
  }
  recieveTime = millis();
  updateRecieved = true;
  startDAQ = true;
  measurement_interval_in_seconds = measurementInterval/1000.0; 
  Wire.onRequest(requestMeasurement); // register event  
}



void setTimer1(){
  //reset TC1 register
  TCCR1A = 0x00; 
  TCCR1B = 0x00;
  TCNT1 = 0x00;
  
  // Set timer 1 in Normal mode  
  TCCR1A |= (0<<WGM10);
  TCCR1A |= (0<<WGM11);
  TCCR1B |= (0<<WGM12);
  TCCR1B |= (0<<WGM13);

  // Use external clock on rising edge
  TCCR1B |= (1<<CS11);
  TCCR1B |= (1<<CS12);
  TCCR1B |= (1<<CS12); 

  // set current timer value to 0
  TCNT1 = 0;
}

float batteryLevel(){

  float sum = 0;
  for (uint8_t i = 1; i <= 100; i++) {
        sum += analogRead(A1);
        delay(1); 
        }
 
  voltage = (((sum/100.0)*1.11)/1023.0)*4.765;
  sum = 0;    
  return voltage;
}
