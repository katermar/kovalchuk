#pragma once
#include "Header.h"
#include "File.h"

using namespace std;

template<class T>
class TextFile : private File
{
public:
	TextFile(string filename) : File(filename);
	~TextFile() : File();

private:
	friend ofstream &operator<< (ofstream &out, T& obj);
	friend ifstream &operator>> (ifstream &in, T& obj);
};

