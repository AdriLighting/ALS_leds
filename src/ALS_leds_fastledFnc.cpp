#include "ALS_leds_fastledFnc.h"
#include "FastLED_RGBW.h"


void fill_solid( struct CRGBW * leds, int numToFill, const struct CRGB& color)
{
    for( int i = 0; i < numToFill; i++) {
        leds[i] = color;
    }
}
void fill_solid( struct CRGBW * leds, int numToFill, const struct CHSV& color)
{
    for( int i = 0; i < numToFill; i++) {
        leds[i] = color;
    }
}

void fill_white(struct CRGBW * leds, int numToFill, const struct CRGBW& color){
	for(int i = 0; i < numToFill; i++){
		leds[i] = color;
	}
}

void fill_solid( struct CRGBW * leds, const struct CRGB& color, int start, int end)
{
    for( int i = start; i < end; i++) {
        leds[i] = color;
    }
}