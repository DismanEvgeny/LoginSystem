#include <iostream>
#include "login.h"
#include "crypt.h"
using namespace std;

bool check_username(string username) {
	bool check{ true };
	for  (auto ch : USERNAME_RESTRICTED_CHARS)
	{
		if (username.find(ch) != std::string::npos) {
			check = false;
			cout << "Username has restricted char(s)\n";
			break;
		}
	}

	if (username.length() < USERNAME_MIN_LENGTH || username.length() > USERNAME_MAX_LENGTH) {
		check = false;
		cout << "Username must be longer than " << USERNAME_MIN_LENGTH << " and shorter than " << USERNAME_MAX_LENGTH << " characters\n";
	}

	if (user_exists(username)) {
		check = false;
		cout << "User \"" << username << "\" exists\n";
	}

	return check;
}

bool check_password(string password) {
	bool check{ true };
	for (auto ch : PASSWORD_RESTRICTED_CHARS)
	{
		if (password.find(ch) != std::string::npos) {
			check = false;
			cout << "Password has restricted char(s)\n";
			break;
		}
	}

	if (password.length() < PASSWORD_MIN_LENGTH || password.length() > PASSWORD_MAX_LENGTH) {
		check = false;
		cout << "Password must be longer than " << PASSWORD_MIN_LENGTH << " and shorter than " << PASSWORD_MAX_LENGTH << " characters\n";
	}

	return check;
}

string get_password_from_user() {
#ifdef _WIN32
	HANDLE hStdInput
		= GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode{ 0 };

	// Create a restore point Mode
	// is know 503
	GetConsoleMode(hStdInput, &mode);

	// Enable echo input
	// set to 499
	SetConsoleMode(
		hStdInput,
		mode & (~ENABLE_ECHO_INPUT));
#endif // _WIN32

#ifdef UNIX_OS
	termios oldt;
	tcgetattr(STDIN_FILENO, &oldt);
	termios newt = oldt;
	newt.c_lflag &= ~ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
#endif // UNIX_OS

	
	// Take input
	string ipt{};
	getline(cin, ipt);
	cout << endl;

#ifdef _WIN32
	// Restore the mode
	SetConsoleMode(hStdInput, mode);
#endif

	return ipt;
}

bool compare_passwords(string username, string password) {
	bool result{};
	string password_from_file{ get_password_from_file(username) };
	password = encrypt(password);
	return password == password_from_file;
}

// login user
int login()
{
	string username{}, password{};
	bool success{false};
	// int rc{ 0 };
	cout << "Username:\t";
	getline(cin, username);

	if (!user_exists(username)) {
		cout << "User " << username << " doesn't exist.\n";
		return RC_USER_DOESNT_EXIST;
	}

	for (int i = 0; i < PASSWORD_INPUT_RETRIES; i++) {
		cout << "Password:\t";
		password = get_password_from_user();
		if (compare_passwords(username, password)) {
			success = true;
			break;
		}
	}
	if (!success) {
		return RC_PASSWORDS_DONT_MATCH;
	}

	return 0;
}


// register user
int register_user()
{
	string username{}, password{}, password_for_check{};
	bool check{false};
	int rc{0};

	// Get username from input + check it
	while (!check)
	{
		username = "";
		cout << "Enter username:\t";
		getline(cin, username);
		check = check_username(username);
	}
	check = false;

	// Get password from input + check it
	while (!check) {
		password = ""; password_for_check = "";
		cout << "Enter password:   ";
		password = get_password_from_user();
		check = check_password(password);
		if (!check)
			continue;
		cout << "Reenter password: ";
		password_for_check = get_password_from_user();
		check = (password == password_for_check);
	}

	// register user
	rc = register_user(username, password);

	return rc;
}

// register user with predefined name and password
int register_user(string username, string password)
{
	int rc{ 0 };
	if (user_exists(username)) {
		return RC_USER_EXISTS;
	}

	password = encrypt(password);
	rc = create_user_file(username, password);

	return rc;
}

// check if user exists
bool user_exists(string username)
{
	bool exists{ user_file_exists(username) };

	return exists;
}