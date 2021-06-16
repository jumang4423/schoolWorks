# A jungle(a genre of music) generator which is a combo of generic drum machine and synth, but dedicated to building amen breaks

## Motivation: 
I have wanted this kind of program since I started getting into music production. 


When you imagine making amen breaks, you try to use digital audio workstations or launchpad things. 


The disadvantage is that there is only a small amount of expandability. 

To solve this, I will make something more funny and flexible.

## Purpose: 
Using multiple “variable resistor”s, Control the sound volume, 

position, panning, pitch and the number of loops


To manipulate or slice the sound file, I use a python library called “pydub” in python language


## Functional spec.
variable resistors will send python volume, position, panning, 


pitch and the number of loops variables via gpio library.


Also, I use the button to turn on/off the background sound.


Python will get some variables from gpio, so cut the sound and push datas using the variables.

## System Architecture

Used Devices

Raspberry pi

One display component

Variable resistor

## Referred exercises

None

## Schedule

I would like to release the initial version at least within 2 weeks.


After the 2 weeks, I will debug or add some new features.

------------------------------------------------------------------------

# pyenv

- source jungle_generator/bin/activate.fish

- pip freeze

- pip install ```<hoge>```