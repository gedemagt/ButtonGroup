
#ifndef BUTTONGROUP_H
#define BUTTONGROUP_H

#include "Arduino.h"

struct button {
	uint8_t lastButtonState;
	uint8_t pin;
	uint8_t mode;
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
	void setDebounce(long debounce);

private:
	button* buttons; // An array with the buttons
	uint8_t count; // The number of buttons
	uint8_t dim; // The allocated array size
	long long_click_threshold; // How long before a long click is toggled
	long debounce_time; // How long we wait for debouncing
	uint8_t buttonState; // The current read button state
	long current; // The current time reading
};
#endif