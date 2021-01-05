#include "ALS_leds_segment.h"

leds_segemnt_runtime::leds_segemnt_runtime(){

}

leds_segemnts		* leds_segemntsArray[10];
int 				leds_segemntsArray_pos	= 0;

leds_segemnts::leds_segemnts(uint32_t start, uint32_t end, boolean dir){

	leds_segemntsArray[leds_segemntsArray_pos] = this;
	_start 		= start;
	_stop 		= end;
	_reverse 	= dir;
	leds_segemntsArray_pos++;
}

leds_segment * leds_segmentPtr = nullptr;
leds_segment * leds_segmentPtr_get(){return leds_segmentPtr;}
leds_segment::leds_segment(){
	leds_segmentPtr = this;
}
void leds_segment::segemnt_new(uint32_t start, uint32_t end, boolean dir){
	new leds_segemnts(start, end, dir);
	new leds_segemnt_runtime();
}
void leds_segment::segemnt_max(uint8_t &  max){
	max = leds_segemntsArray_pos;
}
leds_segemnts * leds_segment::segemnt_get(int pos){
	return leds_segemntsArray[pos];
}

void leds_segment::isSegemnt(boolean & ret){
	if (leds_segemntsArray_pos == 0) ret = false;
	ret = true;
}



aramoire_segemnts	* aramoire_segemntsArray[8];
int					aramoire_segemntsArray_pos	= 0;

aramoire_segemnts::aramoire_segemnts(uint32_t start, uint32_t end, boolean dir){

	aramoire_segemntsArray[aramoire_segemntsArray_pos] = this;
	_start 		= start;
	_stop 		= end;
	_reverse 	= dir;
	aramoire_segemntsArray_pos++;
}

aramoire_segemnt * aramoire_segemntPtr = nullptr;
aramoire_segemnt * aramoire_segemntPtr_get(){return aramoire_segemntPtr;}
aramoire_segemnt::aramoire_segemnt(){
	aramoire_segemntPtr = this;
}
void aramoire_segemnt::segemnt_new(uint32_t start, uint32_t end, boolean dir, aramoire_side side){
	if (side == aramoire_side_left) {
		_segements_left[_segements_left_pos] = new aramoire_segemnts(start, end, dir);
		_segements_left_pos++;
	}
	if (side == aramoire_side_right) {
		_segements_right[_segements_right_pos] = new aramoire_segemnts(start, end, dir);
		_segements_right_pos++;
	}	
}
void aramoire_segemnt::segemnt_leftRight(int numleds){
	_left 	= new uint16_t[(numleds/2)+1];
	_right 	= new uint16_t[(numleds/2)+1];

	uint16_t count = 0;

	for (int i = 0; i < _segements_left_pos; ++i)
	{
		aramoire_segemnts * ptr = _segements_left[i];
		for (int i = ptr->_start; i < ptr->_stop; ++i)
		{
			/* code */
			_left[count] = i;
			count++;
		}
	}

	count = 0;
	for (int i = 0; i < _segements_right_pos; ++i)
	{
		aramoire_segemnts * ptr = _segements_right[i];
		for (int i = ptr->_start; i < ptr->_stop; ++i)
		{
			/* code */
			_right[count] = i;
			count++;
		}
	}
	// fsprintf("\n[count] %d\n", count)
	// fsprintf("\n[_left]\n")
	// for (int i = 0; i < count; ++i)
	// {
	// 	/* code */
	// 	fsprintf("[%10d] %d\n", i, _left[i] );
	// }
	// fsprintf("\n[_right]\n")
	// for (int i = 0; i < count; ++i)
	// {
	// 	/* code */
	// 	fsprintf("[%10d] %d\n", i, _right[i] );
	// }	
}
void aramoire_segemnt::segemnt_max(uint8_t &  max){
	max = aramoire_segemntsArray_pos;
}
aramoire_segemnts * aramoire_segemnt::segemnt_get(int pos){
	return aramoire_segemntsArray[pos];
}

void aramoire_segemnt::isSegemnt(boolean & ret){
	if (aramoire_segemntsArray_pos == 0) ret = false;
	ret = true;
}

