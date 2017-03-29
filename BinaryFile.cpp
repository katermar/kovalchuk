#include "head/BinaryFile.h"

using namespace std;

template <class T>
BinaryFile<T>::BinaryFile(string filename) : File(filename)
{

}

template <class T>
BinaryFile<T>::BinaryFile() : File()
{
}

template <class T>
BinaryFile<T>::~BinaryFile()
{
	fileIn.close();
	fileOut.close();
}

template <class T>
void BinaryFile<T>::write(T& obj)
{
	fileOut.close();
	fileOut.open(filename, ios::binary | ios::app);
	fileOut << reinterpret_cast<char*>(obj);
	fileOut.close();
}

template <class T>
void BinaryFile<T>::read(T& obj)
{
	if (filename.empty() || filename.length() == 0) throw new FileException(205, "EmptyFileNameException");
	if (this->isEnd()) throw new FileException(206, "FileEndException");

	fileIn >> reinterpret_cast<char*>(obj);
}