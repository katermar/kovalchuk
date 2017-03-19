#pragma once
#include <iostream>
#include <string>
#include "Exeption1.h"

using namespace std;

class MyExceptionIn : MyException
{
public:
	MyExceptionIn();
	MyExceptionIn(int n, string s);
	~MyExceptionIn();

	string what();

private:
	string message;
};

