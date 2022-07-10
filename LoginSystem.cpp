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

#include <iostream>
#include "global.h"
#include "login.h"
#include <filesystem>

using namespace std;

void check_startup();

int main()
{
	check_startup();

	char inp{};
	bool quit{ false };
	cout << "___________________ Login System ___________________\nLogin(L), Register(r) or Exit(e) ? : \t";
	while (!quit) {
		quit = true;
		inp = getchar();
		cin.ignore();
		switch (inp)
		{
		case 'l':
			login();
			break;
		case 'r':
			register_user();
			break;
		case 'e':
			quit = true;
			break;
		default:
			cout << "! Only \'l\', \'r\' or \'e\'\n";
			quit = false;
			break;
		}

	}

	return 0;
}

void check_startup()
{
	auto db_path{ filesystem::current_path() };
	db_path.append(DIRNAME);
	bool path_exists{};
	path_exists = filesystem::exists(db_path);
	if (!path_exists) {
		filesystem::create_directory(db_path);
		register_user(TESTUSR1, TESTPSSWD1);
		register_user(TESTUSR2, TESTPSSWD2);
	}
	else {
		if (!user_exists(TESTUSR1))
			register_user(TESTUSR1, TESTPSSWD1);
		if (!user_exists(TESTUSR2))
			register_user(TESTUSR2, TESTPSSWD2);
	}

}