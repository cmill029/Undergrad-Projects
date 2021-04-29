#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>
#include <sstream>
#include <memory>
#include <iterator>
#include <algorithm>
#include <utility>

#include "parseTemps.h"
#include "dataManipulation.h"
#include "output.h"

using CoreTempReading = std::pair<int, std::vector<double>>;

/** This program takes a file name as its own parameter
 * This input file contains a set of CPU core temperatures for 4 different cores at a given time
 * @param argv[1] string containing input file name
 */
int main(int argc, char** argv)
{
    // Input validation
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " input_file_name" << "\n";
        return 1;
    }

    ifstream input_temps(argv[1]);
    if (!input_temps) {
        cout << "ERROR: " << argv[1] << " could not be opened" << "\n";
        return 2;
    }
    // End Input Validation

    // vector generated from parsing input file
    auto readings = parse_raw_temps<std::vector<CoreTempReading>>(input_temps);

    //creation of a vector of pairs for each core containing all interpolation values for that core
    vector<pair<double, double>> core0Interpolation = piecewiseInterpolation(readings, 0); //core 0
    vector<pair<double, double>> core1Interpolation = piecewiseInterpolation(readings, 1); //core 1
    vector<pair<double, double>> core2Interpolation = piecewiseInterpolation(readings, 2); //core 2
    vector<pair<double, double>> core3Interpolation = piecewiseInterpolation(readings, 3); //core 3

    //creation of a pair for each core containing the least squares approximation for that core
    pair<double, double> core0LSA = leastSquaresApproximation(readings, 0); //core 0
    pair<double, double> core1LSA = leastSquaresApproximation(readings, 1); // core 1
    pair<double, double> core2LSA = leastSquaresApproximation(readings, 2); // core 2
    pair<double, double> core3LSA = leastSquaresApproximation(readings, 3); // core 3

    //passes values gathered from previous function and passes them to output 
    printToFile(core0Interpolation, core0LSA, 0); //passes core 0 values to print function
    printToFile(core1Interpolation, core1LSA, 1); //passes core 1 values to print function
    printToFile(core2Interpolation, core2LSA, 2); //passes core 2 values to print function
	printToFile(core3Interpolation, core3LSA, 3); //passes core 3 values to print function
    

   

    return 0;
}

