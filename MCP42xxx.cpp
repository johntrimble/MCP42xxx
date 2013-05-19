#include "Arduino.h"
#include "SPI.h"
#include "MCP42xxx.h"

static const byte WRITE_DATA_COMMAND = 16;
static const byte SHUTDOWN_COMMAND = 32;
static const byte NONE_COMMAND = 48;

MCP42xxx::MCP42xxx(int csPin, int shdnPin, int rsPin) {
  this->csPin = csPin;
  this->shdnPin = shdnPin;
  this->rsPin = rsPin;
  pinMode(this->csPin, OUTPUT);
  digitalWrite(this->csPin, HIGH);
  if( this->shdnPin > -1 ) {
    pinMode(this->shdnPin, OUTPUT);
    digitalWrite(this->shdnPin, HIGH);
  }
  if( this->rsPin > -1 ) {
    pinMode(this->rsPin, OUTPUT);
    digitalWrite(this->rsPin, HIGH);
  }
}

void MCP42xxx::write(MCP42xxx::Channel channel, byte data) {
  digitalWrite(this->csPin,LOW);  
  SPI.transfer(WRITE_DATA_COMMAND|channel);
  SPI.transfer(data);
  digitalWrite(this->csPin,HIGH);
}

void MCP42xxx::shutdown(MCP42xxx::Channel channel) {
  digitalWrite(this->csPin,LOW);
  SPI.transfer(SHUTDOWN_COMMAND|channel);
  SPI.transfer(0);
  digitalWrite(this->csPin,HIGH);
}

void MCP42xxx::hardShutdown() {
  // TODO: Implement this
}

void MCP42xxx::reset() {
  // TODO: Implement this
}
