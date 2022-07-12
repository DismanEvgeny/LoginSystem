#include "encrypt.h"

string decrypt_simple(string str)
{
	string resultStr{};

	for (auto ch : str) {
		resultStr += ch - 12;
	}

	return resultStr;
}