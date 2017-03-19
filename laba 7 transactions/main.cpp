#pragma once
#include "myinterface.cpp"
#include "head\Businessman.h"
#include "head\Businesstourist.h"
#include "head\Person.h"
#include "head\Tourist.h"

using namespace std;

void main()
{
	SetConsoleCP(1251); // ¬вод с консоли в кодировке 1251
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	cout << (char)7 << (char)7 ;
	Interface<int> i;
	i.menuFirst();
}

