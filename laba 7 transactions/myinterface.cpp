#pragma once
#include "head\Header.h"
#include "tree.cpp"
#include "head\Transactions.h"

using namespace std;

template <class T>
class Interface
{
	T ob;
	Tran<Tree<T>> tr;
public:
	Interface() {};
	void menu();
	void menuFirst();
	int check()
	{
		int check;
		cout << "Сохранить изменения?(1/0) ";
		cin >> check;
		return check;
	}
};

template <class T>
void Interface<T> :: menuFirst()
{
	int choice = 0;
	while (choice != 5)
	{
		system("pause");
		system("cls");
		cout << "------------------------------" << endl
			<< setw(20) <<"MENU" << endl
			<< "------------------------------" << endl;
		cout << "1. Работа с Person" << endl
			<< "2. Работа с Tourist" << endl
			<< "3. Работа с Businessman" << endl
			<< "4. Работа с Businesstourist" << endl
			<< "5.Выход" << endl;
		cin >> choice;
		_getch();
		system("cls");
		switch (choice)
		{
		case 1:
			{
				Interface<Person> obj;
				obj.menu();
				break;
			}
		case 2:
			{
				Interface<Tourist> obj;
				obj.menu();
				break;
			}
		case 3:
			{
				Interface<Businessman> obj;
				obj.menu();
				break;
			}
		case 4:
			{
				Interface<Businesstourist> obj;
				obj.menu();
				break;	
			}
		default:
			break;
		}
	}	
}

template <class T>
void Interface<T> :: menu()
{
	Tree<T> tree;
	int choice = 0;
	T a;

	while (choice != 5)
	{
		system("pause");
		system("cls");
		cout << "------------------------------" << endl
			<< setw(20) <<"MENU" << endl
			<< "------------------------------" << endl
			<< "1.Добавить узел" << endl // нельзя отменить последний введенный узел, если это не первый
			<< "2.Удалить узел" << endl // работает
			<< "3.Просмотр данных" << endl
			<< "4.Удалить все узелы" << endl // при удалении все узлов и без сохранения, когда отменяю посл транзакцию, то остается только один узел первый, скорее всего
			<< "5.Выход" << endl
			<< "****** 0. ОТМЕНА ******" << endl;
		cin >> choice;
		_getch();
		system("cls");

		switch (choice)
		{
		case 1:
			cout << "Введите значение узла: ";
			fstream file;
			file.open("new.txt");
			file >> a;
			file << a;
			file.close();
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
				cout << endl << "Данные:" << endl;
				tr->getRoot()->getValue().edge();
				tr->print(tr->getRoot());

			}
			else 
			{
				cout << "Error" << endl;
				break;
			}

			cout << "Введите значение узела: " << endl;
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
				cout << endl << "Данные:" << endl;
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
					cout << "Дерево удалено." << endl;
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

		default:
			break;
		}		
	}
}



