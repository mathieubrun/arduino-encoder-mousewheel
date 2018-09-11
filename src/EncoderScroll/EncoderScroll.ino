#include <Arduino.h>
#include <Mouse.h>
#include <Keyboard.h>

#include "src/Rotary/Rotary.h" // https://github.com/buxtronix/arduino/tree/master/libraries/Rotary
#include "src/Debounce/Debounce.h" // https://github.com/wkoch/Debounce

#define PIN_ENCODER_A 2
#define PIN_ENCODER_B 3
#define PIN_ENCODER_BUTTON 4
#define PIN_BUTTON_A 5
#define PIN_BUTTON_B 6

#define BUTTON_PRESSED 0

#define SERIAL_SPEED 9600

Rotary encoder_wheel(PIN_ENCODER_A, PIN_ENCODER_B);
Debounce button_e(PIN_ENCODER_BUTTON, 10);
Debounce button_a(PIN_BUTTON_A, 10);
Debounce button_b(PIN_BUTTON_B, 10);

void setup() {
  Serial.begin(SERIAL_SPEED);
  Serial.println("started");

  pinMode(PIN_ENCODER_A, INPUT_PULLUP);
  pinMode(PIN_ENCODER_B, INPUT_PULLUP);
  pinMode(PIN_ENCODER_BUTTON, INPUT_PULLUP);

  pinMode(PIN_BUTTON_A, INPUT_PULLUP);
  pinMode(PIN_BUTTON_B, INPUT_PULLUP);

  Mouse.begin();
  Keyboard.begin();
}

bool pressed_a = false;
bool pressed_b = false;
bool pressed_e = false;

void loop() {
  unsigned char encoder_direction = encoder_direction = encoder_wheel.process();

  if (encoder_direction == DIR_CW) {
    Serial.println("CW");
    Mouse.move(0, 0, 1);
  }

  if (encoder_direction == DIR_CCW) {
    Serial.println("CCW");
    Mouse.move(0, 0, -1);
  }

  encoder_direction = DIR_NONE;

  handle_button_press(button_a, &pressed_a, "A", 0xCD); // PLAY_PAUSE
  handle_button_press(button_b, &pressed_b, "B", 0x00);
  handle_button_press(button_e, &pressed_e, "E", 0x00);
}

void handle_button_press(Debounce button, bool *state, char *name, int keycode) {
  if (BUTTON_PRESSED == button.read()) {
    if (!state) {
      Serial.println(name);
      if(keycode > 0) {
        Keyboard.write(keycode);
      }
      *state = true;
    }
  }
  else {
    *state = false;
  }
}

