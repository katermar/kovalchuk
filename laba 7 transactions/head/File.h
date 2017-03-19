#pragma once
#include "Header.h"

template<class T>
class File
{
public:
	File(string filename);
	~File();
	ifstream getInputFile();
	ofstream getOutputFile();
private:
	ifstream fileIn;
	ofstream fileOut;
};

