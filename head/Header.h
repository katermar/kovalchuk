#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <cctype>
#include <string>
#include <fstream>

#include "funcEx.h"

using namespace std;

struct taxData
{
	char date[11];
	double amount;
};

struct borderCross
{
	char date[11];
	char country[20];
};
