/*
 * This example based on one from:
 * http://arduino.cc/en/Tutorial/SPIDigitalPot
 */
#include<SPI.h>
#include<MCP42xxx.h>

MCP42xxx pot(10, -1, -1);

void setup() {
  
}

void loop() {
  for (int channel = MCP42xxx::CHANNEL_0; channel <= MCP42xxx::CHANNEL_1; channel++) {
    // change the resistance on this channel from min to max:
    for (int level = 0; level < 255; level++) {
      pot.write(channel, level);
      delay(10);
    }
  }
  // wait a second at the top:
  delay(100);
  for (int channel = MCP42xxx::CHANNEL_0; channel <= MCP42xxx::CHANNEL_1; channel++) {
    // change the resistance on this channel from min to max:
    for (int level = 0; level < 255; level++) {
      pot.write(channel, 255-level);
      delay(10);
    }
  }
}
