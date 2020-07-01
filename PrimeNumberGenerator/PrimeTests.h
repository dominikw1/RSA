#pragma once
#include "AdditionalHeaders/InfInt.h"
#include "auxillary.h"
class PrimeTest
{
public:
	bool SmallPrimeTest(InfInt num);
	bool FermatTest(InfInt num);
	bool MillerRabinTest(InfInt num);
};