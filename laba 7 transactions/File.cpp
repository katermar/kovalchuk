#include "head\File.h"

using namespace std;

template <class T>
File<T> :: File(string filename)
{
	fileIn.open(filename);
	fileOut.open(filename);
}

template <class T>
File<T> :: ~File()
{
	fileIn.close();
	fileOut.close();
}

template <class T>
File<T> :: ifstream getInputFile()
{
	return fileIn;
}

template <class T>
File<T> :: ofstream getOutputFile()
{
	return fileOut;
}