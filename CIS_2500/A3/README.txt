Erik Zorn-Wallentin    0864583
CIS 2500               Assignment Three

********************************
Compiling the program
********************************
Open terminal to directory that this was installed in. Type make on command line to compile.

********************************
Running the program
********************************
To run the program type... 
bin/runMe <filename>


********************************
What to do while running program
********************************
You can move with w,a,s,d keys or q to quit the game. 
When running the program you can move around (your guy is '@' and the goal is pick up items on the ground
and reach the stairs('%').


********************************
Known limitations
********************************
The program needs the room.txt file to be in the assets folder!
No error checking on the doors if it goes out of bounds for room.
No error checking on any value that has 0  ex. p0,2  
-- could not tell difference between p0,2 and if it did not exist.
If door is on same x plane as the previous room on the same level there will be a problem in the code.
This is important because if the door is at same level as another the person won't be able to teleport!!!
Hero cannot die, and monsters can't die...not implemented yet.
