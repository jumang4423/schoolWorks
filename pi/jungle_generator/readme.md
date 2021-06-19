# A jungle(a genre of music) generator which is a combo of generic drum machine and synth, but dedicated to building amen breaks

## screen

```
b s m 1 2 3 4 5 6 7 8 o
1 d # 0 0 1 0 0 4 5 6 0
```

- b
    
    background sample (range: - to 7(sample number))

- s
    
    main sample (range: - to 7(sample number))

- m
    
    main sample modulation (range: 0 to 128)

- :numbers
    
    break samples (range: - to 7)

- 0
    
    break samples option (range: 0 to 3)

    - 0 sample
    - 1 reverse
    - 2 volume
    - 3 panning


--------------------------------------

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

--------------------------------------

# pyenv

- source jungle_generator/bin/activate.fish

- pip freeze

- pip install ```<hoge>```