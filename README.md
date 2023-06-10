# C-mutex-synchronisation
The problem statement:

A small island has a historic bridge with only one lane that can only hold a limited number of vehicles at a
time without risking collapse. At most, four cars or a combination of one bus and two cars are allowed on
the bridge simultaneously. However, two buses cannot be on the bridge at the same time. If two buses
arrive at the same time, only one can cross while the other waits. All vehicles can travel in one direction
only, and there may be cars or buses waiting on the other side of the bridge.
To manage traffic flow, you need to implement a mutex synchronization mechanism in a multi-threaded
program. A master thread will spawn vehicle threads at regular intervals, and each vehicle thread will call
the functions "ArriveAtBridge(int direction, int vehicleType)" and "ExitTheBridge()" to control traffic
flow.
The "ArriveAtBridge()" function takes two parameters: the direction the vehicle wants to go (0 or 1) and
the type of vehicle (car or bus). When a vehicle thread arrives at the bridge, it calls "ArriveAtBridge()" and
waits until it is allowed to cross the bridge. The function ensures that no more than four cars or one bus
and two cars are on the bridge at any given time. If a bus arrives while there are already two cars on the
bridge, it waits until the bridge is clear. If two buses arrive at the same time, only one can cross while the
other waits.
The "ExitTheBridge()" function is called when a vehicle thread gets off the bridge, potentially allowing
other vehicles to get on. The program should run for a user-specified number of minutes before exiting.
---------------------------------------------------------------------------------------------------------------

The program is implemeted in a linux enviroment, with different threads signifying different vehicles, and mutexes used
to synchronise the travel of vehicles on the bridge. 

The program runs for a defined amount of time, which is set using the sleep() function in main.
