#include <iostream>
#include "pch.h"
#include <windows.h>
#include <conio.h>
#include "stack.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "**************************** STACK ************************************\n"
		<< "========================================================================\n"
		<< "||  Данная программа cоздает шаблон класса для работы со стеком        ||\n"
		<< "|| и выполняет действия с разными типами данных                        ||\n"
		<< "========================================================================\n\n";
	while (1) {
		int select;
		cout << "  Выберете, что необходимо выполнить:\n"
			<< " 1. Стек с действительныи числами\n"
			<< " 2. Стек с целыми числами\n"
			<< " 3. Стек с символами\n"
			<< " 4. Выход\n";
		cout << " Выбрать: ";
		cin >> select;
		switch (select)
		{
			case 1:
			{
				Stack<double> stackSymbol(10);
				double ch;
				int n;
				cout << " Введите кол-во элементов в стеке: ";
				cin >> n;
				for (int i = 0; i < n; i++)
				{
					cout << " Введите число №" << i + 1 << ": ";
					cin >> ch;
					stackSymbol.push(ch); // помещаем элементы в стек
				}

				stackSymbol.PrintSeries(stackSymbol);
				cout << endl;
				break;
			}
			case 2:
			{
				Stack<int> stackSymbol1(10);
				Stack<int> stackSymbol2(10);
				double ch;
				int n;
				cout << " Введите кол-во элементов в стеке: ";
				cin >> n;
				for (int i = 0; i < n; i++)
				{
					cout << " Введите число стека 1 №" << i + 1 << ": ";
					cin >> ch;
					stackSymbol1.push(ch); // помещаем элементы в стек
				}
				for (int i = 0; i < n; i++)
				{
					cout << " Введите число стека 2 №" << i + 1 << ": ";
					cin >> ch;
					stackSymbol2.push(ch); // помещаем элементы в стек
				}

				stackSymbol1.sequence(stackSymbol1, stackSymbol2);
				cout << endl;
				break;;
			}
			case 3:
			{
				Stack<char> stackSymbol(10);
				int ct = 0;
				char ch;
				int n;
				cout << " Введите кол-во элементов в стеке: ";
				cin >> n;
				for (int i = 0; i < n; i++)
				{
					cout << " Введите символ №" << i + 1 << ": ";
					cin >> ch;
					stackSymbol.push(ch); // помещаем элементы в стек
				}
				stackSymbol.hooks();
				cout << endl;
				Stack<char> stackSymbol2(10);
				char ch2;
				int n2;
				cout << " Введите кол-во элементов в стеке: ";
				cin >> n2;
				for (int i = 0; i < n2; i++)
				{
					cout << " Введите символ №" << i + 1 << ": ";
					cin >> ch2;
					stackSymbol.push(ch2); // помещаем элементы в стек
				}
				break;

			}
		}

	}
	return 0;
}