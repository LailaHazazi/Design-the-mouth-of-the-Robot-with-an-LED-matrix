#include <LedControl.h>

// Initialize the LED Matrix
LedControl lc = LedControl(11, 13, 10, 1); // DIN, CLK, CS, # of Matrices

byte mouthClosed[8] = {
  B00000000,
  B00000000,
  B00000000,
  B01110000,
  B01110000,
  B00000000,
  B00000000,
  B00000000
};

byte mouthOpen[8] = {
  B00000000,
  B00010000,
  B00101000,
  B01000100,
  B01000100,
  B00101000,
  B00010000,
  B00000000
};

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop() {
  // Mouth closed (line)
  displayMouth(mouthClosed);
  delay(1000);

  // Mouth open (circle)
  displayMouth(mouthOpen);
  delay(1000);

  // Mouth closed (line)
  displayMouth(mouthClosed);
  delay(1000);
}

void displayMouth(byte mouth[]) {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, mouth[i]);
  }
}
