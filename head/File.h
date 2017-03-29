#pragma once
#include "Header.h"
#include "FileException.h"

template<class T>
class File
{
public:
	explicit File(string filename);
	File();
	virtual ~File();
	void setFilename(string);
	int fileSize();
	void close() throw (FileException);
	bool isEnd() const throw (FileException);
	bool isVeryEnd();
	bool makeEmpty() throw (FileException);
	bool isEmpty();
	virtual void read (T& obj);
	virtual void write (T& obj);
protected:
	//int mode; // 1 - read, 2 - write
	string filename;
	ifstream fileIn;
	ofstream fileOut;
	//	fstream file;
};


