ArduinoMoistureMonitor_with_nails
=================================

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004

Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.

           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
  TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

 0. You just DO WHAT THE FUCK YOU WANT TO.



moisture_rx and tx are an attempt to send the moisture variable from one
arduino to the other.

moisture_function is the moisture code, only put into a function for use
with other probes.

moisture3_all_all_probes is the same as moisture_function only with 3
probes attached. Didnt work very well.

moisture_function_average is the same moisture_function only now it
takes 5 readings and calculates the average for them all, and then uses
that. Im currently using this one on my arduino.



reply #7 is where this code comes from 

http://forum.arduino.cc/index.php/topic,37975.0.html

Layout:


           digital 2---*
                 |
                 \
                 /
                 \ R1
                 /
                 |
                 |
         analog 0----*
                 |
                 |
                 *----> nail 1
                 
                 *----> nail 2
                 |
                 |
                 |
           digital 3---*
