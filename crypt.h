#pragma once
#include <iostream>

#include "global.h"
#include "encrypt.h"
#include "decrypt.h"
#include "conf.h"

using namespace std;

// string encrypt(string str, int method);

string encrypt(string str);

string decrypt(string str, int method);