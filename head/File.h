#pragma once
#include "Header.h"
#include "FileException.h"

template<class T>
class File
{
public:
	explicit File(string filename);
	File();
	virtual void openFile();
	virtual ~File();
	void setFilename(string);
	virtual int fileSize();
	void close() throw (FileException);
	bool isEnd() const throw (FileException);
	virtual bool isVeryEnd();
	virtual bool makeEmpty() throw (FileException);
	bool isEmpty();
	virtual void read (T& obj);
	virtual void read (T& obj, int counter);
	virtual void write (T& obj);
	string getFilename() const;
protected:
	string filename;
	ifstream fileIn;
	ofstream fileOut;
};


