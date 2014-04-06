
#ifndef BUTTONGROUP_H
#define BUTTONGROUP_H

#include "Arduino.h"

struct button {
	int lastButtonState;
	int pin;
	int mode;
	void (*f)();
	long last_rising;
};

class ButtonGroup {
public:
	ButtonGroup(int dimension);
	~ButtonGroup();
	// mode = 0: falling edge
	// mode = 1: rising edge
	// mode = 2: long click
	void addButton(int pin, void (*f)(), int mode);
	void loopButtons();
	void setLongClickThreshold(long threshold);

private:
	button* buttons;
	int count;
	int dim;
	long long_click_threshold;
};
#endif