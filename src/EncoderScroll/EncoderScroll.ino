#include <Mouse.h>
#include <Rotary.h> // https://github.com/buxtronix/arduino/tree/master/libraries/Rotary
#include <Debounce.h> // https://github.com/wkoch/Debounce

#define PIN_ENCODER_A 3
#define PIN_ENCODER_B 4
#define PIN_ENCODER_BUTTON 5
#define PIN_BUTTON_A 6
#define PIN_BUTTON_B 7

Rotary rotary = Rotary(PIN_ENCODER_A, PIN_ENCODER_B);

Debounce button_encoder(PIN_ENCODER_BUTTON, 10); 
Debounce button_a(PIN_BUTTON_A, 10); 
Debounce button_b(PIN_BUTTON_B, 10); 

void setup() {
  Serial.begin(9600);
  Serial.println("started");

  Mouse.begin();
}

void loop() {
  unsigned char result = rotary.process();
  
  if (result == DIR_CW) {
    Serial.println(result);
    Mouse.move(0, 0, 1);
  } 
  else if (result == DIR_CCW) {
    Serial.println(result);
    Mouse.move(0, 0, -1);
  }

  if(button_a.read() == 1) {
    Serial.println("A");
  }
    
  if(button_b.read() == 1) {
    Serial.println("B");
  }
  
  if(button_encoder.read() == 1) {
    Serial.println("encoder");
  }
}
