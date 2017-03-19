#pragma once
#include "head\ExceptionIn.h"

MyExceptionIn :: MyExceptionIn() : MyException()
{
}

MyExceptionIn :: MyExceptionIn(int n, string s)
{
	errorCode = n;
	message =  s;
}

MyExceptionIn :: ~MyExceptionIn()
{
}

string MyExceptionIn :: what()
{
	return "error #" + to_string(errorCode) + " : " + message;
}
