CircularQueue
=============

Generic Circular Queue Buffer implementation for Embedded Systems

Here is the Internal Structure of the Circular Queue

    struct {
	uint8_t * data; 	//To store the Actual Data
	uint16_t max;   	//Maximum Size of the array
	uint16_t front,rear;//Pointer for the queue
	uint16_t inuse;//For protected Queue Handling
    }cqueue_t;`
    

License
--------
Creative Commons Attribution-ShareAlike 3.0 Unported

[CC BY-SA 3.0](http://creativecommons.org/licenses/by-sa/3.0/)

[Full Text](http://creativecommons.org/licenses/by-sa/3.0/legalcode)