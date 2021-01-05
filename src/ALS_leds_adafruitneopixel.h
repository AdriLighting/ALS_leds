
#ifndef ALS_LEDS_ADAFRUITNEOPIXEL_H
	#define ALS_LEDS_ADAFRUITNEOPIXEL_H 

	#include <Adafruit_NeoPixel.h>

	class ledsBase
	{	

	public:
		Adafruit_NeoPixel 	* _leds      	= nullptr;;

		uint16_t			_num_leds 	 	= 0;
		uint16_t			_num_leds_w 	= 0;
		uint16_t			_num_leds_h 	= 0;

		uint16_t			_neoDataPin 	= 0;
		neoPixelType 		_neoLedsType	= 0;

		uint8_t 			_matrixType 	= 15; 
		uint8_t 			_rotation		= 3;

		uint8_t 			_contructor		= 0;
	};



	class leds : public ledsBase
	{	

	public:


		leds(uint16_t n, uint16_t p, neoPixelType t) {

			_neoDataPin 	= p;
			_neoLedsType 	= t;
			_num_leds 		= n;

			_contructor = 4;

			_leds = new Adafruit_NeoPixel(n, p, t);

			#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
			  clock_prescale_set(clock_div_1);
			#endif

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

		void lamp_begin(){ 
			Serial.printf("\n[adafruitneopixel]lamp_begin\n");
			_myLed->_leds->begin();
		}

		void lamp_clear(){
				_myLed->_leds->clear();	
				_myLed->_leds->show();
		}
		void lamp_bri(uint8_t v){
				_myLed->_leds->setBrightness(v);	
				_myLed->_leds->show();
		}
		void lamp_white(uint8_t v){
			Serial.printf("\n[adafruitneopixel]lamp_white\n");
			_myLed->_leds->fill(_myLed->_leds->Color(0, 0, 0, _myLed->_leds->gamma8(v)));
			_myLed->_leds->show();
		}	
	
	};
	leds_setting * leds_settingPtr_get();
	leds_setting * leds_setting_ptr_set(leds_setting * ptr);
	
#endif
