#pragma once
#include <string>
#include "Exeption1.h"

using namespace std;

class MyExceptionIn : MyException
{
public:
	MyExceptionIn();
	MyExceptionIn(int n, string s);
	virtual ~MyExceptionIn();

	string what() override;

private:
	string message;
};

