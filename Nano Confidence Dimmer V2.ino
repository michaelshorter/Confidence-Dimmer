#include <Adafruit_NeoPixel.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(24, PIN, NEO_GRB + NEO_KHZ800);
int pot = 0;
int LDR = 0;

void setup() {

Serial.begin(115200);
pinMode(A0, INPUT); 
pinMode(A1, INPUT); 


  strip.begin();
  strip.show(); // initialize all pixels to "off"
}


void loop() {

int LDR = analogRead(A1); //Read LDR


int pot = analogRead(A0); //Read Potentiometer
pot = map(pot, 0, 1024, 0, 255);  // Map the pot value to Neopixel values
  
  if(LDR>20) //Change this to work with light levels
  {
    pulse();
    Serial.println("ON");
  }
  else
  {
    OFF();
    Serial.println("off");
  }

}

// 0 to 255
void pulse() {
  uint16_t i, j;
  {
  int pot = analogRead(A0);
  Serial.println(pot);

  pot = map(pot, 0, 1024, 0, 255);
  for (j = 10; j < 255; j++) {  //Ramp up brightess
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, pot, 0, 255); //strip.setPixelColor(pixels, R, G, B);
      strip.setBrightness(j);
    }
    strip.show();
       int pot = analogRead(A0);
       pot = map(pot, 0, 900, 0, 255);
    delay(2);
  }

  for (j = 255; j > 10; j--) { //Ramp down brightess
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, pot, 0, 255);
      strip.setBrightness(j);
    }
    strip.show();
      int pot = analogRead(A0);
      pot = map(pot, 0, 1024, 0, 255); //strip.setPixelColor(pixels, R, G, B);
    delay(2);
  }
}
}

void OFF() {
  strip.begin(); // Initialize all pixels to 'off'
  strip.show(); // Initialize all pixels to 'off'
  strip.clear(); // Initialize all pixels to 'off'
}