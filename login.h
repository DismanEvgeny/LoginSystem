#pragma once

#include "io.h"

int register_user();

int register_user(std::string username, std::string password);

int login();

bool user_exists(std::string username);