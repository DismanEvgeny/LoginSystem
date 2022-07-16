#include "io.h"
using namespace std;

bool user_file_exists(string username)
{
	bool exists{  };
	auto file_path{ filesystem::current_path() };

	file_path.append(DB_DIRNAME).append(username);
	exists = filesystem::exists(file_path);

	return exists;
}

int create_user_file(std::string username, std::string password)
{
	auto filename{ filesystem::current_path() };
	filename.append(DB_DIRNAME).append(username);
	int rc{ 0 };
	ofstream user_file{};

	try
	{
		user_file.open(filename);
		user_file << username << endl << password;
	}
	catch (const std::exception&)
	{
		rc = RC_FILE_WRITE_ERROR;
	}

	user_file.close();
	return rc;
}

string get_password_from_file(string username)
{
	auto filename{ filesystem::current_path() };
	filename.append(DB_DIRNAME).append(username);
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

bool conf_file_exists()
{
	bool exists{};

	auto file_path{ filesystem::current_path() };

	file_path.append(DB_DIRNAME).append(CONFIG_FILE_NAME);
	exists = filesystem::exists(file_path);


	return false;
}

int create_conf_file() {
	int rc{ 0 };

	auto filename{ filesystem::current_path() };
	filename.append(CONF_DIRNAME).append(CONFIG_FILE_NAME);
	ofstream config_file{};
	//config_file.open(filename);

	try
	{
		config_file.open(filename);
		config_file << CONF_ENCRYPTION_OPT << "\t" << CONF_ENCRYPTION_OPT_DEFAULT;
	}
	catch (const std::exception&)
	{
		rc = RC_FILE_WRITE_ERROR;
	}

	config_file.close();

	return rc;
}


Configuration load_conf_file()
{
	Configuration config{};

	auto filename{ filesystem::current_path() };
	filename.append(CONF_DIRNAME).append(CONFIG_FILE_NAME);

	ifstream is_file(filename);
	//is_file.open(filename);

	std::string line;
	while (std::getline(is_file, line))
	{
		std::istringstream is_line(line);
		std::string key;
		if (std::getline(is_line, key, '\t'))
		{
			std::string value;
			if (std::getline(is_line, value)) {}
			//store_line(key, value);
		}
	}

	is_file.close();

	return config;
}

void clear_console() {
#ifdef UNIX_OS
	// cout << "\x1B[2J\x1B[H";
#endif // UNIX_OS

#ifdef _WIN32
	system("cls");
#endif // _WIN32
}