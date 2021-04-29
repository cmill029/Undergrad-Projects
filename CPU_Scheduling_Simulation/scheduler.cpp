#include "scheduler.h"

using namespace std;

void fifo(Process[10000]);
void sjf(Process[10000]);
void pwp(Process[10000]);



Process cpuSchedule[10000];


int main()
{
	ifstream inFile;
	string inputName;
	//asks for input file name
	cout << "Enter input file name: ";
	cin >> inputName;

	inFile.open(inputName);

	//reads in the values from the file into the cpuSchedule array
	for(int i=0; i<10000; i++)
	{
		inFile >> cpuSchedule[i].index >> cpuSchedule[i].arrivalTime >> cpuSchedule[i].cpuBurst >> cpuSchedule[i].prio;
		cpuSchedule[i].finish = 0;
		cpuSchedule[i].turnaround = 0;
		cpuSchedule[i].waiting = 0;
		cpuSchedule[i].idle = 0;
		cpuSchedule[i].response = 0;
	}

	inFile.close();

	//sorts array based on arrival time
	sort(cpuSchedule, cpuSchedule + 10000, [](Process const & x, Process const & y) -> bool{return x.arrivalTime < y.arrivalTime ;} );

	fifo(cpuSchedule);
	sjf(cpuSchedule);
	sort(cpuSchedule, cpuSchedule + 10000, [](Process const & x, Process const & y) -> bool{return x.arrivalTime < y.arrivalTime ;} );

	pwp(cpuSchedule);
}



void fifo(Process fifo[])
{
	int totalElapsedTime;
	double throughput;
	double utilization;
	double totalIdle = 0;
	double totalWaiting = 0;
	double totalTurnaround = 0;
	double totalResponse = 0;
	double avgWaitingTime;
	double avgTurnaroundTime;
	double avgResponseTime;


	/**
	*  Initialized the first value in the fifo style to the correct values
	**/
	fifo[0].idle = fifo[0].arrivalTime;
	fifo[0].finish = fifo[0].cpuBurst + fifo[0].arrivalTime;
	fifo[0].turnaround = fifo[0].finish - fifo[0].arrivalTime;
	fifo[0].waiting = fifo[0].finish - fifo[0].arrivalTime - fifo[0].cpuBurst;
	fifo[0].response = 0;
	totalIdle += fifo[0].idle;
	totalWaiting += fifo[0].waiting;
	totalTurnaround += fifo[0].turnaround;
	totalResponse += fifo[0].response;
		
	
	/**
	*  Sets the values for the process array based upon the values calculated for the first indexed item
	**/
	for (int i=1; i<10000; i++)
	{
		if (fifo[i].arrivalTime <= fifo[i-1].finish)
		{
			fifo[i].finish = fifo[i-1].finish + fifo[i].cpuBurst;
		}

		else if(fifo[i].arrivalTime > fifo[i-1].finish)
		{
			fifo[i].idle = fifo[i].arrivalTime - fifo[i-1].finish;
			fifo[i].finish = fifo[i].idle + fifo[i].cpuBurst + fifo[i-1].finish;
		}

		if(fifo[i-1].finish - fifo[i].arrivalTime > 0)
		{
			fifo[i].response = fifo[i-1].finish - fifo[i].arrivalTime;
		}

		else
		{
			fifo[i].response = 0;
		}
		
		fifo[i].turnaround = fifo[i].finish - fifo[i].arrivalTime;
		fifo[i].waiting = fifo[i].turnaround - fifo[i].cpuBurst;

		
		totalIdle += fifo[i].idle;
		totalWaiting += fifo[i].waiting;
		totalTurnaround += fifo[i].turnaround;
		totalResponse += fifo[i].response;
		
	}


	/**
	*  calculates the values of the different data pieces based upon values calculated in the array
	**/
	totalElapsedTime = fifo[9999].finish;
	utilization = ((1.000 - (totalIdle/totalElapsedTime)) * 100.000);
	throughput = 10000.000/(totalElapsedTime);
	avgWaitingTime = totalWaiting/10000.000;
	avgTurnaroundTime = totalTurnaround/10000.000;
	avgResponseTime = totalResponse/10000.000;


	/**
	*  Creates an output file and outputs the different values of the calculated array
	**/ 
	string fileName;
  	ofstream myFile;
  	cout << "Insert FIFO output file name: ";
  	cin >> fileName;
  	myFile.open(fileName);

  	myFile << "FIFO scheduling:";
	myFile << "Number of processes: 10000"  << "\n";
	myFile << "Total elapsed time (for the scheduler): " << totalElapsedTime << "\n";
	myFile << "Throughput (Number of processes executed in units of CPU burst time): "  << fixed << setprecision(3) << throughput << "\n";
	myFile << fixed << setprecision(3);
	myFile << "CPU utilization: " << utilization << "\n";
	myFile << "Average waiting time (in CPU burst times): " << avgWaitingTime << "\n";
	myFile << "Average turnaround time (in CPU burst times): " << avgTurnaroundTime << "\n";
	myFile << "Average response time (in CPU burst times): " << avgResponseTime << "\n\n";

  	myFile << "Index " << "   Arrival time  "<< "   CPU Burst Length " << "  Priority" <<  "    Finish Time" ;
  	myFile << "      Turnaround Time" <<  "      Waiting Time"  << "    Idle Time"  << "      Response Time" << endl;
	for(int i=0; i<10000; i++)
	{
		myFile << setw(4) << fifo[i].index << setw(12)  << fifo[i].arrivalTime << setw(20) << fifo[i].cpuBurst;
        myFile << setw(12) << fifo[i].prio << setw(20) << fifo[i].finish << setw(20) << fifo[i].turnaround << setw(20) << fifo[i].waiting;
        myFile << setw(12) << fifo[i].idle << setw(12) << fifo[i].response << endl;
	}

	myFile.close();
	
}

void sjf(Process sjf[])
{
	int totalElapsedTime;
	double throughput;
	double utilization;
	double totalIdle = 0;
	double totalWaiting = 0;
	double totalTurnaround = 0;
	double totalResponse = 0;
	double avgWaitingTime;
	double avgTurnaroundTime;
	double avgResponseTime;
	int complete = 0;
	int shortest = 0;
	int minm = 2147483647;
	bool check = false;
	int rt[10000];

	/**
	*  Creats an array for the runtime of each of the different processes
	**/
	for(int i=0; i<10000; i++)
	{
		rt[i] = sjf[i].cpuBurst;
	}

	/**
	*  Initialized the first value in the fifo style to the correct values
	**/
	sjf[0].idle = sjf[0].arrivalTime;
	sjf[0].finish = sjf[0].cpuBurst + sjf[0].arrivalTime;
	sjf[0].turnaround = sjf[0].finish - sjf[0].arrivalTime;
	sjf[0].waiting = sjf[0].finish - sjf[0].arrivalTime - sjf[0].cpuBurst;
	sjf[0].response = 0;
	totalElapsedTime += sjf[0].finish;
	totalIdle += sjf[0].idle;
	totalWaiting += sjf[0].waiting;
	totalTurnaround += sjf[0].turnaround;
	totalResponse += sjf[0].response;



	/**
	*  Sets the the values for the process array based upon the values calculated for the first indexed item
	**/
	while(complete != 9999)
	{
		for(int j=1; j<10000; j++)
		{
			if((sjf[j].arrivalTime <= totalElapsedTime) && (rt[j] < minm) && (rt[j] > 0))
			{
				minm = rt[j];
				shortest = j;
				check = true;
			}
		}

		if (check == false)
		{
			totalElapsedTime++;
			continue;
		}

		rt[shortest]--;
		minm = rt[shortest];
		
		if(minm == 0)
		{
			minm = 2147483647;
		}

		if(rt[shortest] == 0)
		{
			complete++;
			check = false;

			sjf[shortest].finish = totalElapsedTime + 1;

			sjf[shortest].waiting = sjf[shortest].finish - sjf[shortest].cpuBurst - sjf[shortest].arrivalTime;
			if(sjf[shortest].waiting < 0)
			{
				sjf[shortest].waiting = 0;
			}
		}
		totalElapsedTime++;
	}

	//sorts the array by the finish time of each process
	sort(cpuSchedule, cpuSchedule + 10000, [](Process const & x, Process const & y) -> bool{return x.finish < y.finish ;} );


	/**
	*  Calculates the different values for the process array
	**/
	cpuSchedule[0].response = 0;
	for(int i=1; i<10000; i++)
	{
		if(sjf[i-1].finish - sjf[i].arrivalTime > 0)
		{
			sjf[i].response = sjf[i-1].finish - sjf[i].arrivalTime;
		}

		else
		{
			sjf[i].response = 0;
		}

		if(sjf[i].arrivalTime > sjf[i-1].finish)
		{
			sjf[i].idle = sjf[i].arrivalTime - sjf[i-1].finish;
		}

		sjf[i].turnaround = sjf[i].finish - sjf[i].arrivalTime;
		sjf[i].waiting = sjf[i].turnaround - sjf[i].cpuBurst;



		totalIdle += sjf[i].idle;
		totalWaiting += sjf[i].waiting;
		totalTurnaround += sjf[i].turnaround;
		totalResponse += sjf[i].response;
	}



	/**
	*  Sets the values calculated based upon the values in the array from above
	**/
	utilization = ((1.000 - (totalIdle/totalElapsedTime)) * 100.000);
	throughput = 10000.000/(totalElapsedTime);
	avgWaitingTime = totalWaiting/10000.000;
	avgTurnaroundTime = totalTurnaround/10000.000;
	avgResponseTime = totalResponse/10000.000;


	/**
	*  Creates an output file and outputs the different values of the calculated array
	**/ 
	string fileName;
  	ofstream myFile;
  	cout << "Insert SJF output file name: ";
  	cin >> fileName;
  	myFile.open(fileName);

  	myFile << "SJF scheduling:";
	myFile << "Number of processes: 10000"  << "\n";
	myFile << "Total elapsed time (for the scheduler): " << totalElapsedTime << "\n";
	myFile << "Throughput (Number of processes executed in units of CPU burst time): "  << fixed << setprecision(3) << throughput << "\n";
	myFile << fixed << setprecision(3);
	myFile << "CPU utilization: " << utilization << "\n";
	myFile << "Average waiting time (in CPU burst times): " << avgWaitingTime << "\n";
	myFile << "Average turnaround time (in CPU burst times): " << avgTurnaroundTime << "\n";
	myFile << "Average response time (in CPU burst times): " << avgResponseTime << "\n\n";

  	myFile << "Index " << "   Arrival time  "<< "   CPU Burst Length " << "  Priority" <<  "    Finish Time" ;
  	myFile << "      Turnaround Time" <<  "      Waiting Time"  << "    Idle Time"  << "      Response Time" << endl;
	for(int i=0; i<10000; i++)
	{
		myFile << setw(4) << sjf[i].index << setw(12)  << sjf[i].arrivalTime << setw(20) << sjf[i].cpuBurst;
        myFile << setw(12) << sjf[i].prio << setw(20) << sjf[i].finish << setw(20) << sjf[i].turnaround << setw(20) << sjf[i].waiting;
        myFile << setw(12) << sjf[i].idle << setw(12) << sjf[i].response << endl;
	}

	myFile.close();
}


void pwp(Process pwp[])
{
	int totalElapsedTime = cpuSchedule[0].arrivalTime;
	double throughput;
	double utilization;
	double totalIdle = 0;
	double totalWaiting = 0;
	double totalTurnaround = 0;
	double totalResponse = 0;
	double avgWaitingTime;
	double avgTurnaroundTime;
	double avgResponseTime;
	int complete = 0;
	int shortest = 0;
	unsigned int rt[10000];
	unsigned int p[10000];
	int at[10000];
	

	/**
	*  creates 3 arrays, 1 for runtime, 1 for priority, and 1 for arrival time
	**/
	for(int i=0; i<10000; i++)
	{
		rt[i] = pwp[i].cpuBurst;
		p[i] = pwp[i].prio;
		at[i] = pwp[i].arrivalTime;
	}


	/**
	*  Calculates the different times to be run based upon their arrival and priority
	**/
	while(complete != 10000)
	{
		for(int i=0; i<10000; i++)
		{
			if(at[i] <= totalElapsedTime && p[i] < p[shortest] && rt[i] > 0)
			{
				shortest = i;
			}
		}

		if(rt[shortest] == cpuSchedule[shortest].cpuBurst)
		{
			cpuSchedule[shortest].response = totalElapsedTime - at[shortest];
		}

		rt[shortest]--;
		totalElapsedTime++;		

		if(rt[shortest] == 0)
		{
			complete++;
			cpuSchedule[shortest].finish = totalElapsedTime;
			p[shortest] = 10;
			//cout << complete << endl;
		}		
	}

	//sorts the array based upon the finish time of the processes
	sort(cpuSchedule, cpuSchedule + 10000, [](Process const & x, Process const & y) -> bool{return x.finish < y.finish ;} );

	//calculates the the total values based on the values in the array
	cpuSchedule[0].response = 0;
	for(int i=0; i<10000; i++)
	{

		if(pwp[i].arrivalTime > pwp[i-1].finish)
		{
			pwp[i].idle = pwp[i].arrivalTime - pwp[i-1].finish;
		}

		pwp[i].turnaround = pwp[i].finish - pwp[i].arrivalTime;
		pwp[i].waiting = pwp[i].turnaround - pwp[i].cpuBurst;



		totalIdle += pwp[i].idle;
		totalWaiting += pwp[i].waiting;
		totalTurnaround += pwp[i].turnaround;
		totalResponse += pwp[i].response;
	}
	
	
	/**
	*  Sets the values calculated based upon the values in the array from above
	**/
	utilization = ((1.000 - (totalIdle/totalElapsedTime)) * 100.000);
	throughput = 10000.000/(totalElapsedTime);
	avgWaitingTime = totalWaiting/10000.000;
	avgTurnaroundTime = totalTurnaround/10000.000;
	avgResponseTime = totalResponse/10000.000;


	/**
	*  Creates an output file and outputs the different values of the calculated array
	**/ 
	string fileName;
  	ofstream myFile;
  	cout << "Insert pwp output file name: ";
  	cin >> fileName;
  	myFile.open(fileName);

  	myFile << "PWP scheduling:";
	myFile << "Number of processes: 10000"  << "\n";
	myFile << "Total elapsed time (for the scheduler): " << totalElapsedTime << "\n";
	myFile << "Throughput (Number of processes executed in units of CPU burst time): "  << fixed << setprecision(3) << throughput << "\n";
	myFile << fixed << setprecision(3);
	myFile << "CPU utilization: " << utilization << "\n";
	myFile << "Average waiting time (in CPU burst times): " << avgWaitingTime << "\n";
	myFile << "Average turnaround time (in CPU burst times): " << avgTurnaroundTime << "\n";
	myFile << "Average response time (in CPU burst times): " << avgResponseTime << "\n\n";

  	myFile << "Index " << "   Arrival time  "<< "   CPU Burst Length " << "  Priority" <<  "    Finish Time" ;
  	myFile << "      Turnaround Time" <<  "      Waiting Time"  << "    Idle Time"  << "      Response Time" << endl;
	for(int i=0; i<10000; i++)
	{
		myFile << setw(4) << pwp[i].index << setw(12)  << pwp[i].arrivalTime << setw(20) << pwp[i].cpuBurst;
        myFile << setw(12) << pwp[i].prio << setw(20) << pwp[i].finish << setw(20) << pwp[i].turnaround << setw(20) << pwp[i].waiting;
        myFile << setw(12) << pwp[i].idle << setw(12) << pwp[i].response << endl;
	}

	myFile.close();
	
}

