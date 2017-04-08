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
void BinaryFile<T> :: openFile()
{	
	fileOut.open(filename, ios::binary | ios::app);
}

template <class T>
void BinaryFile<T>::write(T& obj)
{
	fileOut.write(reinterpret_cast<char*>(&obj), sizeof(obj));
}

template <class T>
void BinaryFile<T>::read(T& obj, int counter)
{
	if (filename.empty() || filename.length() == 0) throw new FileException(205, "EmptyFileNameException");
	if (this->isEnd()) throw new FileException(206, "FileEndException");
	int pos = (sizeof(T)*counter);
	fileIn.seekg( pos == 0 ? 0 : pos);
	fileIn.read(reinterpret_cast<char*>(&obj), sizeof(obj));//fileIn >> reinterpret_cast<char*>(&obj);
}

template <class T>
int BinaryFile<T> :: fileSize()
{	
	int file_size;
	if (!fileIn.is_open()) fileIn.open(filename, ios::binary);
	fileIn.seekg(0, ios::end);
	file_size = int(fileIn.tellg());	// נאחלונ פאיכא
	int n = file_size/sizeof(T); // number of class T objects 
	fileIn.seekg(0);

	return n;
}

template <class T>
bool BinaryFile<T> :: makeEmpty() throw (FileException)
{
	fileIn.close();
	fileOut.close();
	fileOut.open(filename, ios::binary | ios::out | ios::trunc);
	fileOut.close();
	return true;
}

template <class T>
bool BinaryFile<T>::isVeryEnd()
{
	if (!fileIn.is_open()) 
	{
		fileIn.open(filename, ios::binary);
		if (fileIn.eof() || this->isEmpty())
			return true;
		return false;
	}
	if (fileIn.eof())
		return true;
	return false;
}
