#ifndef Packet_h
#define Packet_h

struct Packet
{
  float flowrate = 0;
  unsigned long tstamp = 0;
  float battery = 0;
  float totalizedFlow = 0;
};

#endif
