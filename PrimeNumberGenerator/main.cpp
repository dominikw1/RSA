#include <iostream>
#include <vector>
#include <fstream>
#include "AdditionalHeaders/InfInt.h"
#include "PrimeTests.h"
#include "auxillary.h"
using namespace std;


int main()
{
	ofstream outputFile;
	outputFile.open("primeNumbers.txt");
	// Debug version : outputFile.open("E:\\Users\\domin\\Visual studio\\RSA\\RSA\\primeNumbers.txt");
	ofstream counterFile;
	counterFile.open("cntr.txt");
	// Debug version : counterFile.open("E:\\Users\\domin\\Visual studio\\RSA\\RSA\\cntr.txt");

	InfInt startNum = "10000";
	cout << "Please enter the starting number" << endl;
	cin >> startNum;
	InfInt currNum = startNum;
	bool stop = false;
	PrimeTest tester; 
	InfInt counter = "0";
	cout << "Please enter the number of prime numbers you require." << endl;
	InfInt numPrimes = "1000";
	cin >> numPrimes;
	
	while (!stop)
	{
		
		bool smallPrime = tester.SmallPrimeTest(currNum);
		if (smallPrime)
		{
			if (tester.FermatTest(currNum))
			{
				outputFile << currNum << endl;
				cout << currNum << endl;
				counter++;
			}
		}

		currNum++;
		if (counter > numPrimes)
			stop = true;
	}

	counterFile << counter;
	
	counterFile.close();
	outputFile.close();
	return 0;
}