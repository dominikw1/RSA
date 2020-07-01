#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "auxillary.h"
#include "CRT.h"

#include "InfInt.h"
#include <utility>
#include <random>
#include "PrimNumberHandler.h"
#include "Encryption.h"
using namespace std;



int main()
{
#pragma region Setup
	//----------------------------------------------------------------------
	//--------------------Setup---------------------------------------------
	cout << "----------------------------- SETUP -----------------------------"<<endl;
	cout << "Custom Setup? Press y for custom setup, any other key for automatic setup"<<endl;
	string in;
	cin >> in;
	cout << endl;
	
	PrimNumberHandler pHandler;
	InfInt primNum1 = pHandler.getNum();
	InfInt primNum2 = pHandler.getNum();
	if (in == "y")
	{
		cout << "Please enter two prime numbers bigger than 1000"<<endl;
		cin >> primNum1>>primNum2;
	}
	InfInt N = primNum1 * primNum2;
	
	InfInt e = pHandler.getRelPrime(3, (primNum1 - 1) * (primNum2 - 1));
	if (in == "y")
	{
		cout << "Please enter an exponent e. It has to be a relative prime to " << (primNum1 - 1) * (primNum2 - 1) << endl;
		cout << "A possible e would be: " << e << endl;
		cin >> e;
	}


	cout << "Keys: " << endl;
	//Private Key
	cout << "Private Key" << endl;
	cout << "p and q: " << primNum1 << " " << primNum2 << endl;
	//Public Key
	cout << "Public Key: " << endl;
	cout << "N: " << N << ", e: " << e << endl;
	
	//------------------------------------------------------------------------
	//------------------------------------------------------------------------
#pragma endregion

#pragma region Input
	//------------------------------------------------------------------------
	//------------------------Input-------------------------------------------
	cout << "----------------------------- INPUT -----------------------------"<<endl;
	string Input;
	vector<vector<string>> textInput;
	cout << "Please enter the message to encrypt, a space between every 8th digit. Press strg+Z to enter" << endl;
	while (cin >> Input)
	{
		
		if(Input.length() > 4)
		{	
			vector<string> newInput;
			pair<string, string> Inputs = Auxillary::TeileString(Input);
			Auxillary::Partition(&newInput, InfInt(Inputs.first));
			textInput.push_back(newInput);
			newInput.clear();
			Auxillary::Partition(&newInput, InfInt(Inputs.second));
			textInput.push_back(newInput);
		}
		else
		{
			vector<string> newInput;
			Auxillary::Partition(&newInput, InfInt(Input));
			textInput.push_back(newInput);
		}
				
	}
	cout << "your Input is ";
	vector<InfInt> InputNums;
	for (auto v : textInput)
	{

		InfInt inputNum = Auxillary::textToNum(v);
		InputNums.push_back(inputNum);
		cout << inputNum;
	}
	cout << " (reversed)" << endl<<endl<<endl;

	//---------------------------------------------------------------------------
	//---------------------------------------------------------------------------
#pragma endregion

#pragma region Encryption
	//--------------------------------------------------------------------------
	//--------------------------Encryption--------------------------------------
	cout << "--------------------------- ENCRYPTION ---------------------------" << endl;
	vector<InfInt> cipherTexts;
	for (auto num : InputNums)
	{
		if (num > N)
		{
			cout << "Error, N is too small" << endl;
			return 0;
		}

		
		InfInt cipherText = Encryption::encrypt(num, e, N);
		
		cipherTexts.push_back(cipherText);
	}
	cout << "CipherText: ";
	for(auto c : cipherTexts)
		cout << c;
	cout << endl;
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------
#pragma endregion


#pragma region Decryption
	//----------------------------------------------------------
	//--------------------Decryption----------------------------
	cout << "--------------------------- DECRYPTION ---------------------------" << endl;
	InfInt modulus = (primNum1 - 1) * (primNum2 - 1);
	if (Auxillary::gcd(modulus, e) != 1)
	{
		cout << "error, e is not coprime to mod" << endl;
	}
	vector<InfInt> decrInformation = Auxillary::runGCDext(modulus, e);
	InfInt decrKey = decrInformation[2];
	cout << "Decryption Key is: " << decrKey << endl;
	//cout << "inverse check:" << ((e * decrKey) % modulus)<<endl;
	vector<InfInt> results;
	for (auto c : cipherTexts)
	{
		InfInt res = CRT::fastExponentiation(c, decrKey, primNum1, primNum2, N);
		
		results.push_back(res);
	}
	cout << "using CRT,  your input was: ";
	for(auto r:results)
		cout << (Auxillary::reverseNum(r));
	
	//------------------------------------------------------------
	//-------------------------------------------------------------
#pragma endregion
	cout << endl << endl << endl;
	

	system("pause");
	
}
