#include <ShiftIn.h>

// Init ShiftIn instance with a two chips
ShiftIn<2> shift;

void setup() {
	Serial.begin(9600);
	// declare pins: pLoadPin, dataPin, clockPin
	shift.begin(8, 11, 12);
}

void displayValues() {
	// print out all 16 buttons
	for(int i = 0; i < shift.getDataWidth(); i++)
		Serial.print( shift.state(i) ); // get state of button i
	Serial.println();
}

void loop() {
	if(shift.update()) // read in all values. returns true if any button has changed
		displayValues();
	delay(1);
}