CircularQueue
=============

Generic Circular Queue Buffer implementation for Embedded Systems

Here is the Internal Structure of the Circular Queue

`struct {
	uint8_t * data; 	//To store the Actual Data
	uint16_t max;   	//Maximum Size of the array
	uint16_t front,rear;//Pointer for the queue
	uint16_t inuse;//For protected Queue Handling
}cqueue_t;`