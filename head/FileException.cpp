#pragma once
#include "FileException.h"

FileException::FileException() : MyException()
{
}

FileException::FileException(int n, string s)
{
	errorCode = n;
	message =  s;
}

FileException::~FileException()
{
}

string FileException :: what()
{
	return "error #" + to_string(errorCode) + " : " + message;
}