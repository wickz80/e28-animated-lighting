## e28-animatedLighting
***
Repo for custom LED projects with a BMW E28 535i.  Mostly done with Arduino and WS2812B LED strips.

Here's a demo showing the 'mustang' style
[https://youtu.be/9FpE5VTokXA](https://youtu.be/9FpE5VTokXA)

Wiring diagram for custom LED control box
![LED Control Box](https://github.com/wickz80/e28-animatedLighting/blob/master/arduino.png "LED Control Box")

Schematic for the actual matrix-izing of the NeoFruit strips
![Matrix](https://github.com/wickz80/e28-animatedLighting/blob/master/leds.bmp "LED Matrix diagram")

## Usage
***

Open up your .ino file of choice with ArduinoIDE. Connect your Arduino (I'm using a MEGA 2560) and flash the code using the arrow button.
Modify pin outs as necessary

`#define DATA_PIN_A 30`

`#define DATA_PIN_B 32`

`#define DATA_PIN_C 34`

Connect your Arduino to the LED strips, and power it on.  

## Notes on power supply

Most Arduinos are not capable of supplying enough 5V power to drive more than 20 or so LEDs.

I'd recommend using an external 5V power supply for best performance.  However, the light strips should share a ground with the external power source, otherwise there might be artifacting.
