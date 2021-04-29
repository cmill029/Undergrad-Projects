#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

#include "parseTemps.h"

using namespace std;
/**
 * Prints linear interpolation and least squares approximation of CPU temperatures for each core to a filed named for each core
 * first line is the linear squares approximation followed by all of the lines in the interpolation
 * @param coreInterpolation vector where each value is a par of doubles matching the values in the equation of a line
 * @param lsa pair of doubles where each value is a value in the equation of a line
 * @param coreNumber id representing which core is being printed
 * 
 * @pre (coreNumber >=0 && coreNumber < 4)
 */
void printToFile(vector<pair<double, double>> coreInterpolation, pair<double, double> lsa, int coreNumber){
	string outputFileName = "semesterProject-core-" + to_string(coreNumber) + ".txt"; //add core number to rest of file name
	ofstream myFile(outputFileName);

	int xk;
    int xkPlusOne;

    //output least square approximation equation on first line
    myFile << setw(5) << "xk" << setw(5) << " <= x <" << setw(8) << "xk+1;" << " y_i" ;
    myFile << setw(7) << "=" << setw(11) << lsa.first << " " << "    +" << "       " << lsa.second << "x;" << " type: least-square" << '\n' << '\n';

    //output all interpolation equations line by line
    for(int i=0; i<coreInterpolation.size(); i++){
    	xk = (i*30);
    	xkPlusOne = ((i+1)*30);
    	myFile << fixed << setprecision(4);
    	myFile << setw(5) << xk << " <= x <" << setw(7) << xkPlusOne << "; " << setw(2) << "y_";
    	myFile << setw(7);
    	myFile << left << i << "=" << setw(15);
    	myFile << right << coreInterpolation[i].first << " +" << setw(10) << coreInterpolation[i].second << "x; interpolation" << '\n';
    }
}

#endif