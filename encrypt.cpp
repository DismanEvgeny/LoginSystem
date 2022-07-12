#include "encrypt.h"

string encrypt_simple(string str)
{
	string resultStr{};

	for (auto ch : str) {
		resultStr += ch + 12;
	}

	return resultStr;
}