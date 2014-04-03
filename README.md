ButtonGroup
===========

A little library to control a press-button for the Arduino platform.

It is pretty easy used. The available methods are:

``` cpp
ButtonGroup(int dimension);
void addButton(int pin, void (*f)(), int mode);
void loopButtons();
void setLongClickThreshold(long threshold);
```

Initialize a ButtonGroup with the desired maximum number of buttons.
Add the buttons you want to use in the setup() method. The inputs are:

``` cpp ButtonGroup(int dimension);```: John
``` cpp ButtonGroup(int dimension);```: John
``` cpp ButtonGroup(int dimension);```: John


pin (it will register the pinMode for you).
2. the function to be called.
3. mode. There are three modes: falling edge(0), rising edge(1) or long press(2). You can then choose how long time the long-click-threshold should be. The standard is 1000 ms.

In the loop you just call loopButtons()-method and everything is now taken care of.

Enjoy!


