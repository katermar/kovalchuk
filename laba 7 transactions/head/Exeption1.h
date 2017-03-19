#pragma once
#include <string>

using namespace std;

class MyException
{
public:
	MyException();
	MyException(int);
	~MyException();
	virtual string what();
protected:
	int errorCode;
};



