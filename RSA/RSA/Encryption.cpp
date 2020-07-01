#include "Encryption.h"

InfInt Encryption::encrypt(InfInt plainText, InfInt e, InfInt N)
{
	return Auxillary::exponent(plainText, e)%N;
}
