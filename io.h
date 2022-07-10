#pragma once
#include <fstream>
#include <filesystem>
#include "global.h"

bool user_file_exists(std::string username);

int create_user_file(std::string username, std::string password);

std::string get_password_from_file(std::string username);
