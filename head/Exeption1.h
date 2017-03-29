#pragma once
#include <string>

using namespace std;

class MyException
{
public:
	MyException();
	explicit MyException(int);
	virtual ~MyException();
	virtual string what();
protected:
	int errorCode;
};



