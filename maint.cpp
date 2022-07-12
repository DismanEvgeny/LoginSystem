#include "maint.h"

static Configuration configuration{};

bool check_startup()
{
	bool check{ true };

	auto db_path{ filesystem::current_path() };
	auto conf_path{ db_path };
	db_path.append(DB_DIRNAME);
	conf_path.append(CONF_DIRNAME);
	bool path_exists{};

	// configuration path check
	path_exists = filesystem::exists(conf_path);
	if (!path_exists) {
		// path doesn't exist
		filesystem::create_directory(conf_path);
		check = create_conf_file() == 0;
	}
	else if(conf_file_exists()) {
		// path exists but no conf file 
		check = create_conf_file() == 0;
	}
	else {
		// both path and conf file exist

	}

	if (check) {
		configuration = load_conf_file();
	}

	// db path check
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

	return check;

}

int start() {

	char inp{};
	bool quit{ false };
	string result{};
	int rc{};
	cout << "___________________ Login System ___________________\nLogin(L), Register(r) or Exit(e) ? : \t";
	while (!quit) {
		quit = true;
		inp = getchar();
		cin.ignore();

		switch (inp)
		{
		case 'l':
			rc = login();
			if (rc != 0) {
				result.assign("Login failed. RC = " + rc);
			}
			else {
				result.assign("Login succeed!");
			};
			break;

		case 'r':
			rc = register_user();
			if (rc != 0) {
				result.assign("Registrtion failed. RC = " + rc);
			}
			else {
				result.assign("Registrtion completed normally.");
			};
			break;

		case 'e':
			result.assign("Goodbye!");
			quit = true;
			break;
		case 'q':
			result.assign("Goodbye!");
			quit = true;
			break;
		default:
			cout << "! Only \'l\', \'r\' or \'e\'\n";
			quit = false;
			break;
		}

	}

	cout << endl << result << endl;

	return 0;
}


/*
* 
*		Private functions
* 
*/
int check_configuration() {
	int rc{ 0 };



	return rc;
}