#include <iostream>
#include "login.h"
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

// login user
int login()
{
	return 0;
}

// register user
int register_user()
{
	string username{}, password{}, password_for_check{};
	bool check{false};
	while (!check)
	{
		username = "";
		cout << "Enter username:\t";
		getline(cin, username);
		check = check_username(username);
	}
	check = false;
	while (!check) {
		password = ""; password_for_check = "";
		cout << "Enter password:\t";
		getline(cin, password);
		check = check_password(password);
		if (!check)
			continue;
		cout << "Reenter password:\t";
		getline(cin, password_for_check);
		check = (password == password_for_check);
	}
	register_user(username, password);

	return 0;
}

// register user with predefined name and password
int register_user(string username, string password)
{
	if (user_exists(username)) {
		return RC_USER_EXISTS;
	}

	//	TODO 
	// encrypt password
	create_user_file(username, password);

	return 0;
}

// check if user exists
bool user_exists(string username)
{
	bool exists{ user_file_exists(username) };

	return exists;
}