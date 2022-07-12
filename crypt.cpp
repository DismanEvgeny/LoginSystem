#include "crypt.h"

/*
* 
*	Private functions
* 
*/

string encrypt(string str, int method)
{
	string resultStr{};

	switch (method)
	{
	case CONF_ENCRYPTION_OPT_NOECNRYPT:
		resultStr = str;
		break;
	case CONF_ENCRYPTION_OPT_SIMPLE:
		resultStr = encrypt_simple(str);
	default:
		break;
	}

	return resultStr;
}


/*
* 
*	Public functions
* 
*/

string encrypt(string str) {
	return encrypt(str, configuration.get_encryption());
}


string decrypt(string str, int method)
{

	string resultStr{};

	switch (method)
	{
	case CONF_ENCRYPTION_OPT_NOECNRYPT:
		resultStr = str;
		break;
	case CONF_ENCRYPTION_OPT_SIMPLE:
		resultStr = decrypt_simple(str);
	default:
		break;
	}

	return resultStr;
}