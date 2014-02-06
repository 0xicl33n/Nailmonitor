ArduinoMoistureMonitor_with_nails
=================================
moisture_rx and tx are an attempt to send the moisture variable from one
arduino to the other.

moisture_function is the moisture code, only put into a function for use
with other probes.

moisture3_all_all_probes is the same as moisture_function only with 3
probes attached. Didnt work very well.

moisture_function_average is the same moisture_function only now it
takes 5 readings and calculates the average for them all, and then uses
that. Im currently using this one on my arduino.
