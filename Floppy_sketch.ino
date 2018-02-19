#include "Floppy.h"

Floppy alps(80,12,13);

void tick_wrapper(){
	alps.tick();
}

void setup(){
	Serial.begin(115200);
	Timer1.initialize(100);
	Timer1.attachInterrupt(tick_wrapper);
}

void loop(){
	if(Serial.available() > 0){
		int new_period = Serial.parseInt();
		if(new_period != 0){
			alps.setPeriod(new_period);
		}
	}
}