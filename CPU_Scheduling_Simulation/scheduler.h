#ifndef SCHEDULER_H_INCLUDED
#define SCHEDULER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <iomanip>
#include <algorithm>

using namespace std;

/**
* This merely creates a Process struct with all of the individual data values
*/

class Process
{
	public:
		int index;
		int arrivalTime;
		int cpuBurst;
		int prio;
		int finish;
		int turnaround;
		int waiting;
		int response;
		int idle;
};



#endif