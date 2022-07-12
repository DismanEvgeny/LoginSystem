#pragma once
#include <filesystem>
#include <iostream>

#include "io.h"
#include "login.h"
#include "global.h"
#include "rc.h"
#include "conf.h"


using namespace std;

bool check_startup();

int start();

bool check_configuration();


void clear_console();