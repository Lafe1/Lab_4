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
	Stack<double> stackSymbol(10);
	int ct = 0;
	double ch;

	cout << "**************************** STACK ************************************\n"
		<< "========================================================================\n"
		<< "||  Данная программа cоздает шаблон класса для работы со стеком        ||\n"
		<< "|| и выполняет действия с разными типами данных                        ||\n"
		<< "========================================================================\n\n";
	while (1) {
		int select;
		cout << "  Выберете, что необходимо сделать:\n"
			<< " 1. Ввод элементов\n"
			<< " 2. Вывод возрастающей серии последовательности\n"
			<< " 3. Вывести дерево по возрастанию\n"
			<< " 4. Вывести дерево по убыванию\n"
			<< " 5. Выход\n";
		cout << " Выбрать: ";
		cin >> select;
		switch (select)
		{
		case 1:
		{
			int n;
			cout << " Введите кол-во элементов в стеке: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cout << " Введите число №" << i + 1 << ": ";
				cin >> ch;
				stackSymbol.push(ch); // помещаем элементы в стек
			}
			cout << endl;
			while (!_kbhit());
			break;
		}
		case 2:
		{
			stackSymbol.printStack(); // печать стека
			cout << endl;
			while (!_kbhit());
			break;
		}
		case 3:
		{
			stackSymbol.PrintSeries(stackSymbol);
			cout << endl;
			while (!_kbhit());
			break;
			//stackSymbol.printStack(); // печать стека


			//cout << "\n\nУдалим элемент из стека\n";
			//stackSymbol.pop();

			//stackSymbol.printStack(); // печать стека

			//Stack<double> newStack(stackSymbol);

			//cout << "\n\nСработал конструктор копирования!\n";
			//newStack.printStack();

			//cout << "Второй в очереди элемент: " << newStack.Peek(2) << endl;

		}
		}

	}
	return 0;
}