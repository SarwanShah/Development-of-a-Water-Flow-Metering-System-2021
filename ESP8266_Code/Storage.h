#include"Packet.h"

class Storage
{
  protected:
    uint8_t storageSize = 64;  //Queue Size
    uint8_t headPointer = 0;   // Head and Tail Pointer to keep track of queue size and dequeueing values
    uint8_t tailPointer = 0;
 public:
    Storage();                    //Initilization Constructo
    Packet Queue[64];    
    void enQueue(Packet data);     //
    Packet deQueue();  
    bool isQueueFull();
    bool isQueueEmpty();
};

//constructor
Storage::Storage()
{
  headPointer = 0;
  tailPointer = 0;
}


void Storage::enQueue(Packet data){
  //adds a value in the queue and increments the headpointer
  Queue[headPointer].flowrate = data.flowrate;
  Queue[headPointer].tstamp = data.tstamp;
  Queue[headPointer].battery = data.battery;
  Queue[headPointer].totalizedFlow = data.totalizedFlow;
  headPointer++;
}

Packet Storage::deQueue(){
  Packet returnData;
  //removes a value from the queue and increments the tailpointer
  if (tailPointer < headPointer - 1) { 

    returnData.flowrate = Queue[tailPointer].flowrate; 
    returnData.tstamp = Queue[tailPointer].tstamp;
    returnData.battery = Queue[tailPointer].battery;
    returnData.totalizedFlow = Queue[tailPointer].totalizedFlow;
  
    Queue[tailPointer].flowrate = 0;
    Queue[tailPointer].tstamp = 0;
    Queue[tailPointer].battery = 0;
    Queue[tailPointer].totalizedFlow = 0;
    
    tailPointer++; 
    return returnData; 
    }
    
  else {
    returnData.flowrate = Queue[tailPointer].flowrate;
    returnData.tstamp = Queue[tailPointer].tstamp;
    returnData.battery = Queue[tailPointer].battery;
    returnData.totalizedFlow = Queue[tailPointer].totalizedFlow;
    Queue[tailPointer].flowrate = 0;
    Queue[tailPointer].tstamp = 0;
    Queue[tailPointer].battery = 0;
    Queue[tailPointer].totalizedFlow = 0;
    tailPointer = 0;
    headPointer = 0;
    return returnData;
    }
}

bool Storage::isQueueFull(){
  //checks if the queue is full, by comparing headpointer index to queue size.
  return (headPointer == storageSize);
}

bool Storage::isQueueEmpty(){
  //checks if the queue is full, by comparing headpointer index to queue size.
  return (headPointer == 0);
}
