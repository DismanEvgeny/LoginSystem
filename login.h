#pragma once

#include "io.h"
#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32
#ifdef UNIX_OS
#include <termios.h>
#include <unistd.h>
#endif // UNIX_OS


int register_user();

int register_user(std::string username, std::string password);

int login();

bool user_exists(std::string username);