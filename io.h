#pragma once
#include <fstream>
#include <filesystem>
#include "global.h"
#include "Configuration.h"

bool user_file_exists(std::string username);

int create_user_file(std::string username, std::string password);

std::string get_password_from_file(std::string username);

bool conf_file_exists();

int create_conf_file();

Configuration load_conf_file();