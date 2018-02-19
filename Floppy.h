#ifndef FLOPPY_H
#define FLOPPY_H

#include "Arduino.h"
#include "TimerOne.h"
#define FORWARD 0
#define REVERSE 1

class Floppy{
public:
	Floppy(int maximum_position, int direction_pin, int step_pin);		// CTOR
	void tick();
	void step();		// step once
	void setPeriod(int T);
private:
	int MAX_POS;		// number of steps from 0 to the max position
	int PULSE_WIDTH = 2;// pulse width in μs
	int PERIOD = 0;		// period in μs
	int TICK;			// current time in μs
	int DIR_PIN;		// pin to which the direction signal is driven
	int STEP_PIN;		// pin to which the step signal is driven
	int POS;			// current head position
	int DIR; 			// current head direction	
};

#endif
