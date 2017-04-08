#pragma once
#include "head/TextFile.h"
#include "F://BSUIR//2 kurs//нно//laba 7 transactions/File.cpp"

template<class T>
TextFile<T> :: TextFile(string filename) : File(filename)
{

}

template <class T>
TextFile<T>::TextFile() : File()
{
}

template<class T>
TextFile<T> :: ~TextFile()
{
	fileIn.close();
	fileOut.close();
}

template <class T>
void TextFile<T> :: openFile()
{
	fileOut.open(filename, ios::app);
}

template <class T>
void TextFile<T> :: write(T& obj) 
{
	fileOut << obj;
}

template <class T>
void TextFile<T>:: read(T& obj)
{
	if (filename.empty() || filename.length() == 0) throw new FileException(205, "EmptyFileNameException");
	if (this->isEnd()) throw new FileException(206, "FileEndException");

	fileIn >> obj;
}