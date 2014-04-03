#include "ButtonGroup.h"

ButtonGroup::ButtonGroup(int dimension) {

	buttons = new button[dimension];
	count = 0;
}

 ButtonGroup::~ButtonGroup() {

	 delete [] buttons;

}

 void ButtonGroup::addButton(int pin, void (*f)(), int mode){
	button b = {0, 0, pin, mode, f};
	buttons[count] = b;
	pinMode(pin, INPUT);
	count++;
}

void ButtonGroup::loopButtons(){
	for(int i=0; i<count; i++) {
		button& b = buttons[i];
		
		b.buttonState = digitalRead(b.pin);
		switch(b.mode) {
		case 0:
			if (b.buttonState == 0 && b.lastButtonState == 1) {
				(b.f());
			}
			break;
		case 1:
			if (b.buttonState == 1 && b.lastButtonState == 0) {
				(b.f());
			}
			break;
		case 2:
			break;
		}

		
		b.lastButtonState = b.buttonState;
	}
}