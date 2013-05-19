#ifndef MCP42xxx_h
#define MCP42xxx_h

#include "Arduino.h"

class MCP42xxx
{
  public:
  	enum Channel { NONE=0, CHANNEL_0=1, CHANNEL_1=2, BOTH=3 };

    MCP42xxx(int csPin, int shdnPin, int rsPin);
    void write(MCP42xxx::Channel channel, byte value);
    void shutdown(Channel channel);
    void hardShutdown();
    void reset();
  private:
    int csPin;
    int shdnPin;
    int rsPin;
};

#endif