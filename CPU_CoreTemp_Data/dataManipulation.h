#ifndef DATA_MANIPULATION_H_INCLUDED
#define DATA_MANIPULATION_H_INCLUDED


#include "parseTemps.h"



/**
 * perform piecewise interpolation on all the values for core temperatures
 * the points that this function uses are x = time and y = cpu temperature
 * 
 * @param readings container containing all of the temperature readings from the input file
 * @param coreNumber number of core that interpolation is being calculated for
 * 
 * @return vector of pairs of doubles that contain values for the interpolation equation
 */

template<typename CoreTempReadingContainer>
vector<pair<double, double>> piecewiseInterpolation(CoreTempReadingContainer readings, int coreNumber){
	
    vector<double> core0;
    vector<double> core1;
    vector<double> core2;
    vector<double> core3;
    vector<double> coreT;

    for (const CoreTempReading& theReading : readings) {

        const vector<double>& coreTemps = theReading.second;

        //places values into individual core vectors
        core0.push_back(coreTemps[0]);
        core1.push_back(coreTemps[1]);
        core2.push_back(coreTemps[2]);
        core3.push_back(coreTemps[3]);
    }

    switch(coreNumber){
    	case 0:
    		coreT = core0;
    		break;
    	case 1:
    		coreT = core1;
    		break;
    	case 2:
    		coreT = core2;
    		break;
    	case 3:
    		coreT = core3;
    		break;
    }

    vector<pair<double, double>> interpolationResult;
    for(int i=0; i<coreT.size()-1; i++){
    	pair<double, double> tempValues;
    	double yF=0, yL=0, xF=0, xL=0; //variables for x and y values of points
    	xF = i*30;
    	xL = (i+1)*30;
    	yF = coreT[i];
    	yL = coreT[i+1];

    	tempValues.first = ((yF*xL) - (yL*xF))/(30);
    	tempValues.second = (-yF + yL)/(30);
    	interpolationResult.push_back(tempValues);
    }

    return interpolationResult; //returns vector containing pairs of values for interpolation equations
}

/**
 * function performs least squares approximation for CPU core temperatures
 * the points that this function uses are x = time and y = cpu temperature
 *
 * @param readings container containing all of the temperature readings from the input file
 * @param coreNumber number of core that interpolation is being calculated for
 *
 * @return pair of doubles that equate to the values in the least squares approximation equation
 */
template<typename CoreTempReadingContainer>
pair<double, double> leastSquaresApproximation(CoreTempReadingContainer readings, int coreNumber){
	 

    vector<double> core0;
    vector<double> core1;
    vector<double> core2;
    vector<double> core3;
    vector<double> coreT;

    double xSums = 0;
    double xSquareSums = 0;
    double ySums = 0;
    double xySums = 0;
    double time = 0;

    for (const CoreTempReading& theReading : readings) {

        const vector<double>& coreTemps = theReading.second;

        //places values into individual core vectors
        core0.push_back(coreTemps[0]);
        core1.push_back(coreTemps[1]);
        core2.push_back(coreTemps[2]);
        core3.push_back(coreTemps[3]);

        xSums += theReading.first;
        xSquareSums += (theReading.first)*(theReading.first);
    }


    switch(coreNumber){
    	case 0:
    		coreT = core0;
    		break;
    	case 1:
    		coreT = core1;
    		break;
    	case 2:
    		coreT = core2;
    		break;
    	case 3:
    		coreT = core3;
    		break;
    }
    
    pair<double, double> leastSquaresResult; //intializes a result to return

    //loops through a core calculating different values to go into the XTX|XTY matrix
    for(int j=0; j<coreT.size()-1; j++){
    	ySums += coreT[j];
    	xySums += time*coreT[j];
    	time += 30;
    }

   

    double arr[2][3]; //initializes array representing XTX|XTY
    
    arr[0][0] = coreT.size() - 1;
    arr[0][1] = xSums;
    arr[0][2] = ySums;

    arr[1][0] = xSums;
    arr[1][1] = xSquareSums;
    arr[1][2] = xySums;
	

    const int nrows = 2; // number of rows
    const int ncols = 3; // number of columns

    int lead = 0; 
    //this loop calculates RREF of XTX|XTY matrix to calculate the c0 and c1 values for least squares approximation equation
    while (lead < nrows) {
        double d, m;

        for (int r = 0; r < nrows; r++) { // for each row ...
            /* calculate divisor and multiplier */
            d = arr[lead][lead];
            m = arr[r][lead] / arr[lead][lead];

            for (int c = 0; c < ncols; c++) { // for each column ...
                if (r == lead)
                    arr[r][c] /= d;               // make pivot = 1
                else
                    arr[r][c] -= arr[lead][c] * m;  // make other = 0
            }
        }
        lead++;
    }

    leastSquaresResult.first = arr[0][2];
    leastSquaresResult.second = arr[1][2];

    return leastSquaresResult; //returns pair containing values of c0 and c1
}


#endif