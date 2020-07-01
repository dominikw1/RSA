#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "auxillary.h"
#include "InfInt.h"
#include <random>
#include <filesystem>
#include <assert.h>
class PrimNumberHandler
{
public:
	//constructor
	PrimNumberHandler();
	//destructor
	~PrimNumberHandler();
	//files with primeNumbers and the count of lines in that file
	ifstream primeNumerFile;
	ifstream cntrFile;
	//pointers to the files
	InfInt numLines;
	ifstream* file;
	ifstream* CntrFile;
	
	//functions to be used in main
	InfInt getNum();
	InfInt getRelPrime(InfInt start, InfInt num);

};