#include "Floppy.h"

Floppy::Floppy(int maximum_position, int direction_pin, int step_pin)
: MAX_POS(maximum_position)
,    DIR_PIN(direction_pin)
,    STEP_PIN(step_pin) 
,    TICK(0)
{
	pinMode(DIR_PIN,OUTPUT);
	pinMode(STEP_PIN,OUTPUT);
}

void Floppy::step(){
	if(POS >= MAX_POS){
		DIR = REVERSE;
		digitalWrite(DIR_PIN,DIR);
	}
	else if(POS <= 0){
		DIR = FORWARD;
		digitalWrite(DIR_PIN,DIR);
	}
	DIR == FORWARD ? POS++ : POS--;
	digitalWrite(STEP_PIN,0);
	delay(PULSE_WIDTH);
	digitalWrite(STEP_PIN,1);
}

void Floppy::tick(){
	if(TICK == PERIOD/100){
		step();
		TICK=0;
	}
	TICK++;
}

void Floppy::setPeriod(int T){
	PERIOD = T;
	TICK = 0;
}