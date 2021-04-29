# CPUSCHED
CPUSCHED is a cpu scheduling simulation, it simulates 10000 processes being run by a CPU and then orgainizes them based on the different 
types of scheduling. This doesn't have a makefile because it was not required for the project.

## Installation
use g++ compiler in order to run code

## Usage
```bash
g++ scheduler.cpp
./a.out
```
## Tests
Once a.out is exectuted the user will be prompted for an input file, which contains the test data, followed by 
being asked for 3 output files one for FIFO, SJF, and PWP scheduling accordingly.
The datagen.cpp file is there to generate random sets of data to be used, if a new random set is wished to be created,
compile datagen.cpp with g++ and run the a.out. This will ask you for a test file name, as well as the average time interval
between processes(if this is done then the scheduler must be compiled again unless the executable name for the datagen is 
made to be different than the scheduler).

Included in this directory are multiple sets of sample input and output files, fifo.txt, sjf.txt, and pwp.txt are output files
for those scheduling types respectively. test1.txt, test2.txt, and test3.txt will be sample data files that the output files 
are based off. The number of the test will match the number of the output file that followed it.
