# casa0016
When I studied in the quiet zone of Library last month, I noticed that there were always students talking, and they didn't seem to notice that this behavior had affected the people around them.
Moreover, there was no one to deal with the report on the corresponding link in their library. At the same time, I observed that even if the report was bad, the classmates around did not come out to stop them
Until they get quiet on their own. Therefore, I think it is necessary to build a decibel meter to detect the noise amount of each seat and give feedback to students in some ways when the sound exceeds the set value.

# sensor
1.LM386: The LM386 is an audio amplifier that amplifies signals from capacitive microphones. The reason for choosing this is that only by using it can the decibel value be output. If you only need to input the high and low level, you can also choose LM393.

2.Condenser microphone: The main function is to acquire sound.

3.arduino: The microcontroller board of this project.

4.Hazard: Used to get data from arduino and connect wifi to send the data through mqtt protocol.

5.Raspberry PI: Used for data storage.

6.Lcd board: Displays real-time data.


# Project goal
My project goal is to arrange this decibel meter in the library of ucl east, which can detect the decibel value within a certain range. When the decibel value is higher than the set value, users at the location can be prompted through the led strip or lcd board.
The decibel values were then transmitted through the mqtt protocol and analyzed using influxdb and grafana tools. If the decibel value is higher than the set value for a long time, manual maintenance can be carried out by adding administrators.





resource：https://circuitdigest.com/microcontroller-projects/arduino-sound-level-measurement
