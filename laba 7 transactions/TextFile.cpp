#pragma once
#include "head\TextFile.h"

template<class T>
TextFile<T> :: TextFile(string filename) : File(filename)
{

}

template<class T>
TextFile<T> :: ~TextFile()
{

}

template<class T>
ofstream &operator<< (TextFile<T> &out, T& obj)
{
	ofstream of = out.getOutputFile();
	of << obj;
	return of;
}

template<class T>
ifstream &operator>> (ifstream &in, T& obj)
{
	ifstream f = in.getOutputFile();
	f >> obj;
	return f;
}