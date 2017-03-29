#pragma once
#include "head/Exeption1.h"

MyException::MyException()
{
	errorCode = 1;
}

MyException::MyException(int n)
{
	errorCode = n;
}

string MyException :: what() 
{
	return "MyException";
}

MyException::~MyException()
{
}