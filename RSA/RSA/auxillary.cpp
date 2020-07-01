#include "auxillary.h"

vector<InfInt> Auxillary::toBinary(InfInt num)
{
    vector<InfInt> binaryForm;

    for (int i = 0; num > 0; i++)
    {
        binaryForm.push_back(num % 2);
        num = num / 2;
    }
    reverse(binaryForm.begin(), binaryForm.end());
    return binaryForm;
}
InfInt Auxillary::exponent(InfInt base, InfInt exp)
{
    InfInt res = base;
    if (exp == 0)
        return "1";
    vector<InfInt> binExp = toBinary(exp);
    int index = 1;
    while (index < binExp.size())
    {
        res *= res;
        if (binExp[index] == 1)
            res *= base;
        index++;
    }

    return res;
}

InfInt Auxillary::gcd(InfInt num1, InfInt num2)
{
    if (num2 == 0)
        return num1;
    return gcd(num2, InfInt(num1 % num2));
}

InfInt Auxillary::textToNum(vector<string> text)
{
    //does not turn text into numbers yet, only accepts numbers of digits digits
   
    int digits = 1;
    vector<InfInt> textNums;
    for (auto word : text)
    {
        textNums.push_back(textToNum(word));
    }
    int counter = 0;
    InfInt retVal = 0;
    for (InfInt wordNum : textNums)
    {
        retVal += InfInt(wordNum * (exponent(exponent(10, digits), counter)));
        counter++;
    }
    return retVal;
}

InfInt Auxillary::textToNum(string text)
{//same thing as above
    return InfInt(text);
}

InfInt Auxillary::gcdExtended(InfInt a, InfInt b, InfInt* x, InfInt* y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    InfInt x1, y1;
    InfInt gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
vector<InfInt> Auxillary::runGCDext(InfInt a, InfInt b) {
    InfInt x, y;
    vector<InfInt> retVals;
    InfInt gcd = gcdExtended(a, b, &x, &y);
    InfInt res = (y % a + a) % a;
    retVals.push_back(gcd);
    retVals.push_back(x);
    retVals.push_back(res);
    return retVals;
}

InfInt Auxillary::reverseNum(InfInt num)
{
    vector<char> res;
    for (auto c : num.toString())
        res.push_back(c);
    std::reverse(res.begin(), res.end());
    string retVal;
    for (auto c : res)
    {
        retVal.push_back(c);
    }
    InfInt intForm = retVal;
    return intForm;
}

void Auxillary::Partition(vector<string>* res, InfInt num)
{
    if (num / 10 > 0)
    {
        Partition(res, num / 10);
        res->push_back((num % 10).toString());
    }
    else
        res->push_back(num.toString());
}

pair<string, string> Auxillary::TeileString(string s)
{
    if (s.length() == 1)
        return make_pair(s, "");
    string s1;
    string s2;
    for (int i = 0; i < s.length(); i++)
    {
        if (i <= s.length() / 2)
            s1.push_back(s[i]);
        else
            s2.push_back(s[i]);
    }
    return make_pair(s1, s2);
}

