#pragma once
#include <string>
#include "Exeption1.h"

using namespace std;

class FileException: MyException
{
public:
	FileException();
	FileException(int n, string s);
	virtual ~FileException();

	string what() override;

private:
	string message;
};