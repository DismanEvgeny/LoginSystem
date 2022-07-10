#include "io.h"
using namespace std;

bool user_file_exists(string username)
{
	bool exists{  };
	auto file_path{ filesystem::current_path() };

	file_path.append(DIRNAME).append(username);
	exists = filesystem::exists(file_path);

	return exists;
}

int create_user_file(std::string username, std::string password)
{
	auto filename{ filesystem::current_path() };
	filename.append(DIRNAME).append(username);
	ofstream user_file(filename);
	user_file << username << endl << password;

	user_file.close();
	return 0;
}

string get_password_from_file(string username)
{
	auto filename{ filesystem::current_path() };
	filename.append(DIRNAME).append(username);
	ifstream user_file(filename);
	string line{};
	bool isPsswd{ false };
	while (getline(user_file, line)) {
		if (isPsswd) {
			break;
		}
		isPsswd = true;
	}

	user_file.close();
	return line;
}