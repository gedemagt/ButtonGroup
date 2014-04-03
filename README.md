ButtonGroup
===========

A little library to control a press-button for the Arduino platform.

It is pretty easy used:

Initialize a ButtonGroup with the desired maximum number of buttons.
Add the buttons you want to use in the setup() method. The inputs are:

1. pin (it will register the pinMode for you)\n 
2. the function to be called\n
3. mode. There are three modes: falling edge(0), rising edge(1) or long press(2). You can then choose how long time the long-click-threshold should be. The standard is 1000 ms.\n

In the loop you just call loopButtons()-method and everything is now taken care of.

Enjoy!


