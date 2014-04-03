ButtonGroup
===========

A little library to control several press-buttons for the Arduino platform.

It is pretty easy used. The available methods are:

``` cpp
ButtonGroup(int dimension);
void addButton(int pin, void (*f)(), int mode);
void loopButtons();
void setLongClickThreshold(long threshold);
```

Initialize a ButtonGroup with the desired maximum number of buttons.
Add the buttons you want to use in the setup() method. The inputs are:

1. ```ButtonGroup(int dimension);```: Initialized a new ButtonGroup instance with a capacity specified by dimension.
2. ```void addButton(int pin, void (*f)(), int mode);```: Adds a button. This should be called in the Arduino's setup()-method. pin is the input pin-number (it will register the pinMode for you); f is the function to be called when a button press is registered; mode is the type of press the button will respond to, there are three modes: falling edge(0), rising edge(1) or long press(2).
3. ```void setLongClickThreshold(long threshold);```: Set how long the button should be pressed before it is registered as a long press. The default is 1000 ms.
4. ```void loopButtons();```: This should be called in the Arduino's loop()-method.

Enjoy!


