#pragma once
#ifndef STACK_H
#define STACK_H

#include <cassert> // ��� assert
#include <iostream>
#include <iomanip> // ��� setw

using namespace std;

template <typename T>
class Stack
{
private:
	T *stackPtr;                      // ��������� �� ����
	const int size;                   // ������������ ���������� ��������� � �����
	int top;                          // ����� �������� �������� �����
public:
	Stack(int = 10);                  // �� ��������� ������ ����� ����� 10 ���������
	Stack(const Stack<T> &);          // ����������� �����������
	~Stack();                         // ����������

	inline void push(const T &);     // ��������� ������� � ������� �����
	inline void pop();                   // ������� ������� �� ������� ����� � ������� ���
	inline void Clear();
	inline void sort(Stack<T> &);
	inline void printStack();         // ����� ����� �� �����
	inline void hooks();
	inline const T &Peek(int) const; // n-� ������� �� ������� �����
	inline int getStackSize() const;  // �������� ������ �����
	inline T *getPtr() const;         // �������� ��������� �� ����
	inline int getTop() const;        // �������� ����� �������� �������� � �����
	inline void PrintSeries(Stack<T> &);
	inline void sequence(Stack<T> &, Stack<T> &);
};

// ���������� ������� ������� ������ STack

// ����������� �����
template <typename T>
Stack<T>::Stack(int maxSize) :
	size(maxSize) // ������������� ���������
{
	stackPtr = new T[size]; // �������� ������ ��� ����
	top = 0; // �������������� ������� ������� �����;
}

// ����������� �����������
template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) :
	size(otherStack.getStackSize()) // ������������� ���������
{
	stackPtr = new T[size]; // �������� ������ ��� ����� ����
	top = otherStack.getTop();

	for (int ix = 0; ix < top; ix++)
		stackPtr[ix] = otherStack.getPtr()[ix];
}

// ������� ����������� �����
template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr; // ������� ����
}

// ������� ���������� �������� � ����
template <typename T>
inline void Stack<T>::push(const T &value)
{
	// ��������� ������ �����
	assert(top < size); // ����� �������� �������� ������ ���� ������ ������� �����

	stackPtr[top++] = value; // �������� ������� � ����
}

// ������� �������� �������� �� �����
template <typename T>
inline void Stack<T>::pop()
{
	// ��������� ������ �����
	assert(top > 0); // ����� �������� �������� ������ ���� ������ 0

	stackPtr[--top]; // ������� ������� �� �����

}

template <typename T>
inline void Stack<T>::Clear()
{
	for (int ix = top - 1; ix >= 0; ix--)
	{
		assert(top > 0); // ����� �������� �������� ������ ���� ������ 0

		stackPtr[--top]; // ������� ������� �� �����
	}

}

// ������� ���������� n-� ������� �� ������� �����
template <class T>
inline const T &Stack<T>::Peek(int nom) const
{
	//
	assert(nom <= top);

	return stackPtr[top - nom]; // ������� n-� ������� �����
}

// ����� ����� �� �����
template <typename T>
inline void Stack<T>::printStack()
{
	for (int ix = top - 1; ix >= 0; ix--)
		cout << "|" << setw(4) << stackPtr[ix] << endl;
}

// ������� ������ �����
template <typename T>
inline int Stack<T>::getStackSize() const
{
	return size;
}

// ������� ��������� �� ���� (��� ������������ �����������)
template <typename T>
inline T *Stack<T>::getPtr() const
{
	return stackPtr;
}

template <typename T>
inline void Stack<T>::sort(Stack<T> & stackNew)
{
	double temp;
	for (int i = 0; i < stackNew.top; i++)
		for (int j = 0; j < stackNew.top; j++)
		{
			if (stackNew.stackPtr[i] > stackNew.stackPtr[j])
			{
				temp = stackNew.stackPtr[i];
				stackNew.stackPtr[i] = stackNew.stackPtr[j];
				stackNew.stackPtr[j] = temp;
			}
		}
	stackNew.printStack();
}


// ������� ������ �����
template <typename T>
inline int Stack<T>::getTop() const
{
	return top;
}

template <typename T>
inline void Stack<T>::hooks()
{
	int hook1 = 0, hook2 = 0, hook3 = 0;
	int i = 0;
	for (int i = top - 1; i >= 0; i--)
	{
		if (stackPtr[i] == '{') hook1++;
		if (stackPtr[i] == '(') hook2++;
		if (stackPtr[i] == '[') hook3++;
		if (stackPtr[i] == '}') hook1--;
		if (stackPtr[i] == ')') hook2--;
		if (stackPtr[i] == ']') hook3--;
	}

	if (hook1 == 0 && hook2 == 0 && hook3 == 0)
	{
		cout << " ������ ����������� �����" << endl;

	}
	else
	{
		cout << " ������ ����������� �� �����" << endl;

	}

}

template <typename T>
inline void Stack<T>::PrintSeries(Stack<T> & stack)
{
	Stack<double> stackNew(10);
	double ch;

	cout << "���������: " << endl;
	for (int i = top - 1; i >= 0; i--)
	{
		if (stack.stackPtr[i - 1] <= stack.stackPtr[i])
		{
			stackNew.push(stack.stackPtr[i]); // �������� �������� � ����
		}
		if (stack.stackPtr[i - 1] > stack.stackPtr[i] || i == 0)
		{
			stackNew.printStack();
			stackNew.Clear();
		}
	}
}

template <typename T>
inline void Stack<T>::sequence(Stack<T> & stack1, Stack<T> & stack2)
{
	Stack<double> stackNew(20);

	cout << " ���������: " << endl;



	for (int i = top - 1; i >= 0; i--)
	{

		stackNew.push(stack1.stackPtr[i]); // �������� �������� � ����
		stackNew.push(stack2.stackPtr[i]); // �������� �������� � ����
	}
	stackNew.sort(stackNew);
}		


#endif // STACK_H