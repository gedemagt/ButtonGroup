
#ifndef BUTTONGROUP_H
#define BUTTONGROUP_H

#include "Arduino.h"

struct button {
	int buttonState;
	int lastButtonState;
	int pin;
	void (*f)(int);
};

class ButtonGroup {
public:
	ButtonGroup(int dimension);
	~ButtonGroup();
	virtual void addButton(int pin, void (*f)(int));
	virtual void loopButtons();

private:
	button* buttons;
	int count;
};
#endif