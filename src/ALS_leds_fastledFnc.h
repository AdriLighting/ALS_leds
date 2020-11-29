#ifndef ALS_LEDS_FASTLEDFNC
	#define ALS_LEDS_FASTLEDFNC 
	#include "FastLED_RGBW.h"

	void fill_solid( struct CRGBW * leds, int numToFill, const struct CRGB& color);

	void fill_solid( struct CRGBW * leds, int numToFill, const struct CHSV& color);

	void fill_white( struct CRGBW * leds, int numToFill, const struct CRGBW& color);	

	void fill_solid( struct CRGBW * leds, const struct CRGB& color, int start, int end);
#endif