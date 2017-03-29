#pragma once
#include "Header.h"
#include "F://BSUIR//2 kurs//нно//laba 7 transactions/File.cpp"

using namespace std;

template<class T>
class TextFile : public File<T>
{
public:
	explicit TextFile(string filename);
	TextFile();
	~TextFile();
	void write(T& obj) override;
	void read(T& obj) override;

	//template<class F>
	//TextFile<F> operator<< (TextFile<F> &out, F& obj) throw (FileException);
	//template<class F>
	//TextFile<F> operator>> (TextFile<F> &in, F& obj) throw (FileException);
};

