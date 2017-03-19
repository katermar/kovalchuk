#pragma once
#include "head\Exeption1.h"

MyException::MyException()
{
	errorCode = 1;
}

string MyException :: what() 
{
	return "MyException";
}

MyException::~MyException()
{
}