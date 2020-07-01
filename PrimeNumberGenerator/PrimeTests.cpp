#include "PrimeTests.h"

bool PrimeTest::SmallPrimeTest(InfInt num)
{
    if (num % 2 == 0)
        return false;
    for (int n = 3; n < 1000; n += 2)
    {
        if (num % n == 0)
            return false;
    }
    return true;
}

bool PrimeTest::FermatTest(InfInt num)
{
    //GCD!!!!!!!!!!!

    for (int a = 12; a < 100; a += 3)
    {
        InfInt gcd = Auxillary::gcd(a, num);
        if (gcd != 1)
        {
            //exponentiation function
            if (Auxillary::exponent(a, num - 1)%num != 1)
            {
                return false;
            }
        }
    }

    return true;
}

bool PrimeTest::MillerRabinTest(InfInt num)
{

    return false;
}
