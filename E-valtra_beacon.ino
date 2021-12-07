#include <FastLED.h>

#define LED_PIN     6
#define NUM_LEDS    20
#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

void setup() {
    delay( 1000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
}

void turnOffAllLeds(){
   for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0, 0, 0);
    }
}

void loop() { 

  //Loop through each led
  for(int i = 0; i < 10; i++) {
    turnOffAllLeds(); // turn all leds off
    // Set the i'th led to orange
    leds[i] = CRGB(255, 130, 0);
    leds[19-i] = CRGB(255, 130, 0); //set on second beacon leds on reversed order
    // Show the leds
    FastLED.show(); 
    
    delay(100); // delay before next led
  }
}
