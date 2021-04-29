#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>

//Program to convert base 10 numbers between [0,1) to base 2
//Created by Chris Miller for CS 417

using namespace std;
int MAX_DIGITS = 8; //max digits after the beginning 0

//
int main(int argc, char *argv[]){

	//loop checking arguments to see if they are within 0 and 1
	//outputs an error if they do not fall within that range
	for(int j=1; j<argc; j++)
	{
		double x = atof(argv[j]);
		if(x < 0 || x >= 1)
		{
			cout << "Error, enter values in the domain of [0,1)" << '\n';
			return 1;
		}
	}
	
	//standard output for the beginning of the table
	cout << "| Base 10 |  Base 2  |" << '\n';
	cout << "|:--------|:---------|" << '\n';
	
	//loop that takes the command line arguments, performs the conversion of 
	//base 10 to base 2, creating a character array with the correct output
	//ends by adding the characters in the array to a string that is then displayed
	for(int i=1; i<argc; i++)
	{
		double b10 = atof(argv[i]);
		char result[MAX_DIGITS];
		double x = b10;
		string base2 = "0.";

		for(int q=0; q<MAX_DIGITS; q++)
		{
			x *= 2;

			if(x>=1){
				result[q] = '1';
				x -= 1;
			}
			else if (x<1){
				result[q] = '0';
			}

		}

		for(int z=0; z<MAX_DIGITS; z++){
			base2 += result[z];
		}

		cout << "|" << setw(9) << left << setprecision(MAX_DIGITS-1) << b10 << "|";	
		cout << setw(10) << left << base2 << "|" << '\n';

		
		
	}

	return 0;
}
