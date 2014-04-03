ButtonGroup
===========

A little library to control a press-button for the Arduino platform.

It is pretty easy used:

Initialize a ButtonGroup with the desired maximum number of buttons.
Add the buttons you want to use in the setup() method. The inputs are the pin (it will register the pinMode for you), the function to be called and the mode. There are three modes: falling edge, rising edge or long press.

In the loop you just call loopButtons()-method and everything is now taken care of.

Enjoy!


