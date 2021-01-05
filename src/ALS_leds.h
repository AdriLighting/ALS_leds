		leds_setting * leds_setting_ptr;
		leds_setting * leds_settingPtr_get(){
			return leds_setting_ptr;
		}
		leds_setting * leds_setting_ptr_set(leds_setting * ptr){
			leds_setting_ptr = ptr;
		}	

		#ifdef ALS_USE_LEDSFASTLED
				CRGB 	* stripArray_get(){return leds_settingPtr_get()->_myLed->_leds;}

		#endif		
		#ifdef ALS_USE_LEDSFASTLEDRGBW
				CRGBW 	* stripArray_get(){return leds_settingPtr_get()->_myLed->_leds;}

		#endif						