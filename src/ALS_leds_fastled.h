#ifndef ALS_LEDS_FASTLED_H
	#define ALS_LEDS_FASTLED_H
	// #define USE_LEDSFASTLED

	#include <Arduino.h>

	// #define FASTLED_USE_PROGMEM 1
	// #define FASTLED_ALLOW_INTERRUPTS 1
	// #define FASTLED_INTERRUPT_RETRY_COUNT 0
	// #define FASTLED_INTERNAL
	// #define FL_ALIGN_PROGMEM  __attribute__ ((aligned (4)))
	// #define USE_GET_MILLISECOND_TIMER
	#include <FastLED.h>
	FASTLED_USING_NAMESPACE
	// #define FASTLED_INTERRUPT_RETRY_COUNT 1

	class ledsBase
	{	

	public:
		CRGB 				* _leds      	= nullptr;
		// CRGBW  				* _leds      	= nullptr;

		uint16_t			_num_leds 	 	= 0;
		uint16_t			_num_leds_w 	= 0;
		uint16_t			_num_leds_h 	= 0;

		uint8_t 			_matrixType 	= 15; 
		uint8_t 			_rotation		= 3;

		uint8_t 			_contructor		= 0;
	};



	template<uint8_t DATA_PIN, EOrder RGB_ORDER> class leds : public ledsBase
	{	

	public:


		leds(int numLeds) {

			_num_leds = numLeds;

			_contructor = 1;

			_leds 			= new CRGB[numLeds]();

			FastLED.addLeds<WS2812B, DATA_PIN, RGB_ORDER>(_leds, numLeds);


		}
		leds(int mW, int mH) {

			int numLeds = mH * mW;

			_num_leds 		= numLeds;
			_num_leds_h 	= mH;	 
			_num_leds_w 	= mW;	
			_contructor = 2;

			_leds 			= new CRGB[numLeds]();

			FastLED.addLeds<WS2812B, DATA_PIN, RGB_ORDER>(_leds, numLeds);

		}	
		leds(int mW, int mH, uint8_t matrixType, uint8_t rotation) {

			int numLeds 	= mH * mW;

			_num_leds 		= numLeds;
			_num_leds_h 	= mH;	 
			_num_leds_w 	= mW;	

			_matrixType 	= matrixType;
			_rotation 		= rotation;

			_contructor = 3;

			_leds 			= new CRGB[numLeds]();

			FastLED.addLeds<WS2812B, DATA_PIN, RGB_ORDER>(_leds, numLeds);

		}	

	};


	class leds_setting
	{

		int 		_num_leds;
		int 		_num_leds_w;
		int 		_num_leds_h;
		int 		_rotation;

	public:
		ledsBase 	* _myLed;


		// leds_setting(){};
		leds_setting(ledsBase * myLed){
			_myLed 		= myLed;
			_num_leds 	= myLed->_num_leds;
			_num_leds_w = myLed->_num_leds_w;
			_num_leds_h = myLed->_num_leds_h;
			_rotation 	= myLed->_rotation;
		};


		void numLeds_set(int value){_num_leds = value;}
		void numLeds_get(int & ret){ret = _num_leds;}
		void numLeds_get(int & mw, int & mh){mw = _num_leds_w;mh = _num_leds_h;}

		void lamp_begin(){}
		void lamp_clear(){
			FastLED.clear();
			FastLED.show();	
		}
		void lamp_bri(uint8_t v){
			FastLED.setBrightness(v);
			FastLED.show();
		}
		void lamp_white(uint8_t v){
			Serial.printf("\n[fastled]lamp_white\n");
	        fill_solid(_myLed->_leds, _num_leds, CHSV(0, 0, v)); 
			FastLED.show();	
		}	
	
	};	
	leds_setting * leds_settingPtr_get();
	leds_setting * leds_setting_ptr_set(leds_setting * ptr);	
#endif
