#include "CRT.h"

InfInt CRT::fastExponentiation(InfInt text, InfInt decrKey, InfInt p, InfInt q, InfInt n)
{
    InfInt xP = text % p;
    InfInt xQ = text % q;
    InfInt dP = decrKey % (p - 1);
    InfInt dQ = decrKey % (q - 1);

    InfInt yP = Auxillary::exponent(xP, dP);
    InfInt yQ = Auxillary::exponent(xQ, dQ);
    InfInt cP = Auxillary::runGCDext(p, q)[2];
    InfInt cQ = Auxillary::runGCDext(q, p)[2];

    InfInt res = ((q * cP) * yP + (p * cQ) * yQ) % n;
    return res;
}
