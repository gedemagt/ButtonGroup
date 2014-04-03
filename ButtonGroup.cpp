#include "ButtonGroup.h"

ButtonGroup::ButtonGroup(int dimension) {

	buttons = new button[dimension];
	count = 0;
}

 ButtonGroup::~ButtonGroup() {

	 delete [] buttons;

}

 void ButtonGroup::addButton(int pin, void (*f)()){
	button b = {0, 0, pin, f};
	buttons[count] = b;
	pinMode(pin, INPUT);
	count++;
}

void ButtonGroup::loopButtons(){
	for(int i=0; i<count; i++) {
		button& b = buttons[i];
		
		b.buttonState = digitalRead(b.pin);
		
		if (b.buttonState == 0 && b.lastButtonState == 1) {
			(b.f());
		}
		
		b.lastButtonState = b.buttonState;
	}
}