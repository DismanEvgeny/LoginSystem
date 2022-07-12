#pragma once
#include "rc.h"

#ifdef _WIN32
#define SEPARATOR	"\\"		
#elif 
#define SEPARATOR	"/"
#endif // _WIN32

#if defined(unix) || defined(__unix__) || defined(__unix)
#define UNIX_OS
#endif

// Global
#define DB_DIRNAME		"db"
#define	CONF_DIRNAME	"conf"
#define PASSWORD_INPUT_RETRIES		2
#define CONFIG_FILE_NAME	"login.conf"

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

// Configuration options and defaults
#define CONF_ENCRYPTION_OPT				"ENCRYPTION_OPT"
#define CONF_ENCRYPTION_OPT_NOECNRYPT	0
#define CONF_ENCRYPTION_OPT_SIMPLE		1
#define CONF_ENCRYPTION_OPT_DEFAULT		CONF_ENCRYPTION_OPT_SIMPLE