#pragma once
#include "InfInt.h"
#include <vector> 
#include <utility>
#include <string>

using namespace std;
class Auxillary
{
public:
	static vector<InfInt> toBinary(InfInt num);
	static InfInt exponent(InfInt base, InfInt exp);
	static InfInt gcd(InfInt num1, InfInt num2);
	static InfInt textToNum(vector<string> text);
	static InfInt textToNum(string text);
	static InfInt gcdExtended(InfInt a, InfInt b, InfInt* x, InfInt*y);
	static vector<InfInt> runGCDext(InfInt a, InfInt b);
	static InfInt reverseNum(InfInt num);
	static void Partition(vector<string>* res, InfInt num);
	static pair<string,string> TeileString(string s);
};