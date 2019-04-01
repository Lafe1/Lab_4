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
		<< "||  ������ ��������� c������ ������ ������ ��� ������ �� ������        ||\n"
		<< "|| � ��������� �������� � ������� ������ ������                        ||\n"
		<< "========================================================================\n\n";
	while (1) {
		int select;
		cout << "  ��������, ��� ���������� �������:\n"
			<< " 1. ���� ���������\n"
			<< " 2. ����� ������������ ����� ������������������\n"
			<< " 3. ������� ������ �� �����������\n"
			<< " 4. ������� ������ �� ��������\n"
			<< " 5. �����\n";
		cout << " �������: ";
		cin >> select;
		switch (select)
		{
		case 1:
		{
			int n;
			cout << " ������� ���-�� ��������� � �����: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cout << " ������� ����� �" << i + 1 << ": ";
				cin >> ch;
				stackSymbol.push(ch); // �������� �������� � ����
			}
			cout << endl;
			while (!_kbhit());
			break;
		}
		case 2:
		{
			stackSymbol.printStack(); // ������ �����
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
			//stackSymbol.printStack(); // ������ �����


			//cout << "\n\n������ ������� �� �����\n";
			//stackSymbol.pop();

			//stackSymbol.printStack(); // ������ �����

			//Stack<double> newStack(stackSymbol);

			//cout << "\n\n�������� ����������� �����������!\n";
			//newStack.printStack();

			//cout << "������ � ������� �������: " << newStack.Peek(2) << endl;

		}
		}

	}
	return 0;
}