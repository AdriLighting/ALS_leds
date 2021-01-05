#ifndef ALS_LEDS_SEGMENT_H
	#define ALS_LEDS_SEGMENT_H 

	#include <Arduino.h>


	class leds_segemnt_runtime
	{
		
	public:
            unsigned long   next_time;
            uint32_t         step;
            uint32_t        counter_mode_step;
            uint32_t        counter_mode_call;
            uint8_t         aux_param;   // auxilary param (usually stores a color_wheel index)
            uint8_t         aux_param2;  // auxilary param (usually stores bitwise options)
            uint16_t        aux_param3; // auxilary param (usually stores a segment index)
		leds_segemnt_runtime();
		~leds_segemnt_runtime(){};
		
	};
	class leds_segemnts
	{
		
	public:
		uint32_t 		_start;
		uint32_t 		_stop;
		boolean 		_reverse;
		uint16_t    	_speed;
		uint8_t     	_mode;
		uint8_t     	_options;
		uint8_t     	_intensity;
		uint8_t     	_fade;
		uint32_t    	_colors[3];		
		leds_segemnts(uint32_t start, uint32_t end, boolean dir);
		~leds_segemnts(){};
		
	};
	class leds_segment
	{

	public:

		void segemnt_new(uint32_t start, uint32_t end, boolean dir);

		void isSegemnt(boolean & ret);

		void segemnt_max(uint8_t &  max);

		leds_segemnts * segemnt_get(int pos);

		leds_segment();
		~leds_segment(){};
		
	};
	leds_segment * leds_segmentPtr_get();

	
	enum aramoire_side { 
		aramoire_side_left, 
		aramoire_side_right
	}; 
	class aramoire_segemnts
	{
		
	public:
		uint32_t 		_start;
		uint32_t 		_stop;
		boolean 		_reverse;

		aramoire_segemnts(uint32_t start, uint32_t end, boolean dir);
		~aramoire_segemnts(){};
		
	};


	class aramoire_segemnt
	{

		int 				_segements_left_pos = 0;
		int 				_segements_right_pos = 0;
	public:
		aramoire_segemnts	* _segements_left[4];
		aramoire_segemnts	* _segements_right[4];

		uint16_t	* _left = nullptr;
		uint16_t	* _right = nullptr;

		void segemnt_new(uint32_t start, uint32_t end, boolean dir, aramoire_side side);

		void isSegemnt(boolean & ret);

		void segemnt_max(uint8_t &  max);

		void segemnt_leftRight(int nbr);

		aramoire_segemnts * segemnt_get(int pos);

		aramoire_segemnt();
		~aramoire_segemnt(){};
		
	};
	aramoire_segemnt * aramoire_segemntPtr_get();
#endif