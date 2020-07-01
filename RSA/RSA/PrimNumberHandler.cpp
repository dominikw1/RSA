#include "PrimNumberHandler.h"

PrimNumberHandler::PrimNumberHandler()
{
	string fileName1 = "primeNumbers.txt";
	string fileName2 = "cntr.txt";
	primeNumerFile.open(fileName1.c_str());
	cntrFile.open(fileName2.c_str());
	
	
	file = &primeNumerFile;
	CntrFile = &cntrFile;
	string lineCountStr;
	getline(cntrFile, lineCountStr);
	InfInt lineCnt = lineCountStr;
	numLines = lineCnt;
	

}

PrimNumberHandler::~PrimNumberHandler()
{
	CntrFile->close();
	file->close();
}

InfInt PrimNumberHandler::getNum()
{
	//sets up random num generator and distributes results so we get a random line number
	InfInt start = "1";
	default_random_engine randEng;
	random_device seedGen;
	randEng.seed(seedGen());
	uniform_int_distribution<int> distr(0, numLines.toLongLong());
	InfInt lineNum = InfInt(distr(randEng));

	//gets that random line
	//sadly very inefficient, but only has to be done once
	InfInt lnCntr = 0;
	string currLine;
	do
	{
		getline(*file, currLine);
		lnCntr++;
	} while ((lnCntr != lineNum));
	file->seekg(0, ios::beg);
	return currLine;

}

InfInt PrimNumberHandler::getRelPrime(InfInt start, InfInt num)
{
	//tries a bunch of numbers which could be rel prime, returns first rel prime
	for (InfInt i = start; i < (start + 1000); i++)
	{
		InfInt gcd = Auxillary::gcd(num, i);
		if (gcd == "1")
		{
			return i;
		}
	}
	return 0;
}
