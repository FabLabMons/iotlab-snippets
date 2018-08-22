#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

void setup() {
  Mirf.cePin = 9;
  Mirf.csnPin = 10;
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();

  Mirf.channel = 1;
  Mirf.payload = sizeof(float);
  Mirf.config();

  Mirf.setTADDR((byte *) "nrf50");
  Mirf.setRADDR((byte *) "nrf05");
}

void loop() {
  float value;

  if(Mirf.dataReady()){
    Mirf.getData((byte *) &value);
    Serial.println(value);
  }
}

