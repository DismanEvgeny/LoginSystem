/*
	start
	login (1) or register (2)
		1.	input name
			read file
			if name exists
				input psswd
				read file
				compare
		2.	input name
			read file
			if name ! exists
				input psswd 2 times
				if psswd 1 and 2 are equal
					output to file
*/

#include "maint.h"

int main()
{
	int rc{ 0 };

	if (check_startup()) {
		rc = start();
	}

	return rc;
}