#include "ButtonGroup.h"
#include <assert.h> 

ButtonGroup::ButtonGroup(int dimension) {

	buttons = new button[dimension];
	long_click_threshold = 1000;
	count = 0;
	dim = dimension;
	debounce_time = 10;
	
	current = millis();
}

 ButtonGroup::~ButtonGroup() {

	 delete [] buttons;

}

 void ButtonGroup::addButton(int pin, void (*f)(), int mode){
	assert(count<dim);
	assert(mode<3 && mode>=0);
	button b = {0, pin, mode, f, 0};
	buttons[count] = b;
	pinMode(pin, INPUT);
	count++;
}

void ButtonGroup::loopButtons(){

	if((current + debounce_time) > millis()) return;
	current = millis();
	
	
	for(int i=0; i<count; i++) {
		button& b = buttons[i];
		buttonState = digitalRead(b.pin);
		switch(b.mode) {
		case 0:
			if (buttonState == 0 && b.lastButtonState == 1) {
				(b.f());
			}
			break;
		case 1:
			if (buttonState == 1 && b.lastButtonState == 0) {
				(b.f());
			}
			break;
		case 2:
			if (buttonState == 1 && b.lastButtonState == 0) {
				b.last_rising = current;
			}
			if(buttonState == 0 && b.lastButtonState == 1 && current-b.last_rising > long_click_threshold) {
				(b.f());
			}
			break;
		}
		b.lastButtonState = buttonState;
	}
}


void ButtonGroup::setLongClickThreshold(long threshold) {
	long_click_threshold = threshold;
}

void ButtonGroup::setDebounce(long debounce) {
	debounce_time = debounce;
}