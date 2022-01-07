#include <Adafruit_NeoPixel.h>

#define PIN 2 // GPIO 2 = D4
#define NUMPIXELS 10

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void led_setup()
{
  pixels.begin();
}

void led_loop()
{
  for (int i = 0; i < NUMPIXELS; i++)
  {
    pixels.setPixelColor(i, pixels.Color(255, 255, 255));
    pixels.show();
    delay(500);
  }
}
