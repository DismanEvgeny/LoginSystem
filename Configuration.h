#pragma once
#include "global.h"
class Configuration
{
protected:

	int encryption{ CONF_ENCRYPTION_OPT_DEFAULT };

public:
	//Configuration() {}

	void set_encryption(int _encryption) {
		encryption = _encryption;
	}
	int get_encryption() {
		return encryption;
	}

};

