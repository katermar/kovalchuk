#pragma once
#include "head/Header.h"
#include "tree.cpp"
#include "head/Transactions.h"
#include "F://BSUIR//2 kurs//���//laba 7 transactions/TextFile.cpp"
#include "F://BSUIR//2 kurs//���//laba 7 transactions/File.cpp"

//#include "TextFile.cpp"
#include "head/Businesstourist.h"

using namespace std;

template <class T>
class Interface
{
	T ob;
	Tran<Tree<T>> tr;
public:
	Interface() {};
	void menu(string filename);
	void menuFirst() const;

	static int check()
	{
		int check;
		cout << "��������� ���������?(1/0) ";
		cin >> check;
		return check;
	}
};

template <class T>
void Interface<T> :: menuFirst() const
{
	int choice = 0;
	while (choice != 5)
	{
		system("pause");
		system("cls");
		cout << "------------------------------" << endl
			<< setw(20) <<"MENU" << endl
			<< "------------------------------" << endl;
		cout << "1. ������ � Person" << endl
			<< "2. ������ � Tourist" << endl
			<< "3. ������ � Businessman" << endl
			<< "4. ������ � Businesstourist" << endl
			<< "5.�����" << endl;
		cin >> choice;
		_getch();
		system("cls");
		switch (choice)
		{
		case 1:
			{
				Interface<Person> obj;
				string path("person.txt");
				obj.menu(path);
				break;
			}
		case 2:
			{
				Interface<Tourist> obj;
				obj.menu("tourist.txt");
				break;
			}
		case 3:
			{
				Interface<Businessman> obj;
				obj.menu("businessman.txt");
				break;
			}
		case 4:
			{
				Interface<Businesstourist> obj;
				obj.menu("businesstourist.txt");
				break;	
			}
		default:
			break;
		}
	}	
}

template <class T>
void Interface<T> :: menu(string filename)
{

	Tree<T> tree;
	int choice = 0;
	T a;
	TextFile<T> file;
	file.setFilename(filename);
	try
	{
		tr->read(file);
	}
	catch (FileException exception)
	{
		exception.what();
	}
	//file.close();
	while (choice != 5)
	{
		system("pause");
		system("cls");
		cout << "------------------------------" << endl
			<< setw(20) <<"MENU" << endl
			<< "------------------------------" << endl
			<< "1.�������� ����" << endl // ������ �������� ��������� ��������� ����, ���� ��� �� ������
			<< "2.������� ����" << endl // ��������
			<< "3.�������� ������" << endl
			<< "4.������� ��� �����" << endl // ��� �������� ��� ����� � ��� ����������, ����� ������� ���� ����������, �� �������� ������ ���� ���� ������, ������ �����
			<< "5.�����" << endl
			<< "****** 0. ������ ******" << endl;
		cin >> choice;
		_getch();
		system("cls");

		switch (choice)
		{
		case 1:
			cout << "������� �������� ����: ";
			cin >> a;
			if (!(tr->findNode(a)))
			{
				tr.commit();
				tr.beginTrans();
				tr->newNode(a);
				if (check()) tr.commit();
			}
			break;
		case 2:
			if (tr->getRoot())
			{
				cout << endl << "������:" << endl;
				tr->getRoot()->getValue().edge();
				tr->print(tr->getRoot());

			}
			else 
			{
				cout << "Error" << endl;
				break;
			}

			cout << "������� �������� �����: " << endl;
			cin >> a;
			if (tr->find(tr->getRoot(), a))
			{
				tr.commit();
				tr.beginTrans();
				tr->deleteNode(tr->find(tr->getRoot(), a));
				if (check()) tr.commit();
			}
			break;
		case 3:
			if (tr->getRoot())
			{
				cout << endl << "������:" << endl;
				tr->getRoot()->getValue().edge();
				tr->print(tr->getRoot());

			}
			else cout << "Error" << endl;
			break;
		case 4:
			if (tr->getRoot())
			{
				tr.commit();
				tr.beginTrans();
				tr->clear(tr->getRoot());
				if (check()) 
				{
					tr.commit();
					cout << "������ �������." << endl;
				}
				break;
			}
			else cout << "Error" << endl;

			break;
		case 0:
			{
				tr.deleteTrans();
			}
			break;
		case 5: tr->writeFile(file); break;

		default:
			break;
		}		
	}
}




