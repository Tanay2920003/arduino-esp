#include "HomeSpan.h" 
#include "LED.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  homeSpan.setPairingCode("11122333");
  homeSpan.setQRID("111-22-333");

  homeSpan.begin(Category::Lighting, "My Home LED");
       

  new SpanAccessory();
    new Service::AccessoryInformation();
      new Characteristic::Identify();
    new LED(15); 

   
}


void loop() {
  // put your main code here, to run repeatedly:
  homeSpan.poll();
}
