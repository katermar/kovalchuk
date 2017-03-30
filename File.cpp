#pragma once
#include "head/File.h"
#include "head/FileException.h"

using namespace std;

template <class T>
File<T> :: File(string filename)
{
	this->filename = filename;
}

template <class T>
File<T>::File()
{
}

template <class T>
File<T> :: ~File()
{
	fileIn.close();
	fileOut.close();
}

template <class T>
void File<T>::setFilename(string filename)
{
	this->filename = filename;
}

template <class T>
int File<T> :: fileSize()
{	
	int file_size;
	if (!fileIn.is_open()) fileIn.open(filename);
	fileIn.seekg(0, ios::end);
	file_size = int(fileIn.tellg());				// נאחלונ פאיכא
	fileIn.seekg(0);

	return file_size;
}

template <class T>
void File<T>::close() throw (FileException)
{
	fileIn.close();
	fileOut.close();
}

//
//template <class T>
//int File<T>::getMode() const
//{
//	return mode;
//}


template <class T>
bool File<T> :: makeEmpty() throw (FileException)
{
	fileIn.close();
	fileOut.close();
	fileOut.open(filename, std::ofstream::out | std::ofstream::trunc);
	fileOut.close();
	return true;
}

template <class T>
bool File<T>::isEmpty()
{
	bool size = this->fileSize() > 0 ? false : true;
	return size;
}

template <class T>
void File<T>::read(T& obj)
{
}

template <class T>
void File<T>::read(T& obj, int counter)
{
}

template <class T>
void File<T>::write(T& obj)
{
}

template <class T>
string File<T> :: getFilename() const
{
	return filename;
}


template <class T>
bool File<T>::isEnd() const
{
	return fileIn.eof();
}

template <class T>
bool File<T>::isVeryEnd()
{
	if (!fileIn.is_open()) 
	{
		fileIn.open(filename);
		if (fileIn.eof() || this->isEmpty())
			return true;
		return false;
	}
	if (fileIn.eof())
		return true;
	return false;
}
