#pragma once
#include "rc.h"

#ifdef _WIN32
#define SEPARATOR	"\\"
#elif 
#define SEPARATOR	"/"
#endif // _WIN32

// Global
#define DIRNAME		"db"
#define PASSWORD_INPUT_RETRIES		2

// Test users
#define TESTUSR1	"admin"
#define TESTUSR2	"user"
#define TESTPSSWD1	"admin"
#define TESTPSSWD2	"user"


// Username requirements
#define USERNAME_MAX_LENGTH			16
#define USERNAME_MIN_LENGTH			1
#define USERNAME_RESTRICTED_CHARS	" \\/$&"

// Password requirements
#define PASSWORD_RESTRICTED_CHARS	USERNAME_RESTRICTED_CHARS
#define PASSWORD_MIN_LENGTH			1
#define	PASSWORD_MAX_LENGTH			32