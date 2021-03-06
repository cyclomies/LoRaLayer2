#include <Layer1.h>
#include <LoRaLayer2.h>

#define LORA_CS 18
#define LORA_RST 23
#define LORA_IRQ 26
#define LORA_FREQ 915E6

void setup()
{
  Serial.begin(115200);
  delay(200);

  Serial.println("* Initializing LoRa...");

  Layer1.setPins(LORA_CS, LORA_RST, LORA_IRQ);
  Layer1.setLoRaFrequency(LORA_FREQ);
  LL2.setLocalAddress("c0d3f00d"); // this should either be randomized or set using the wifi mac address
  if (Layer1.init())
  {
    Serial.println(" --> LoRa initialized");
    LL2.init();             // initialize Layer2
    LL2.setInterval(10000); // set to zero to disable routing packets
  }
  else
  {
    Serial.println(" --> Failed to initialize LoRa");
  }
}

void loop()
{    
  LL2.daemon();
}
