# HiQ_Code_Test

#### TUI.h/TUI.cpp

Is the Text-base user interface and is responsible only for
the input and make sure that the input only contains what we want. To start the
main program, you call the *mainLoop()* function which will start asking questions
for the inputs. You are stuck in this process until you have answered all the inputs
with the right format.

#### Simulation.h/Simulation.cpp

This class is responsible for only for reding the command
and execute the commands and see if the simulation was successful or
unsuccessful. Its **important** the simulation is made to take in the right values
and don’t have any error handling for putting the wrong parameters in (this can
be fixt with a simple try and catch error handling). When constructing the
class you will need to put in dimensions of the room, start position and cars
direction and the command. To start the calculation, you just call the *calculatie*
function.

#### Car.h/Car.cpp

Is responsible for having all the information and functions
for the car. Like the direction and the turning functions. The car works with
directions arrays. So, if the car wants to move forward, we can ask the car what
the forward is, depending on the direction the car is facing the car will answer
with a different array. If the car is facing N the moving array is forward = -1
0 (row col) and backward = 1 0 (row col). With this we can now easily just add these
coordinates to the cars current position.
