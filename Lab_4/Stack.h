#pragma once
#ifndef STACK_H
#define STACK_H

#include <cassert> // для assert
#include <iostream>
#include <iomanip> // для setw

using namespace std;

template <typename T>
class Stack
{
private:
	T *stackPtr;                      // указатель на стек
	const int size;                   // максимальное количество элементов в стеке
	int top;                          // номер текущего элемента стека
public:
	Stack(int = 10);                  // по умолчанию размер стека равен 10 элементам
	Stack(const Stack<T> &);          // конструктор копирования
	~Stack();                         // деструктор

	inline void push(const T &);     // поместить элемент в вершину стека
	inline void pop();                   // удалить элемент из вершины стека и вернуть его
	inline void Clear();
	inline void sort(Stack<T> &);
	inline void printStack();         // вывод стека на экран
	inline void hooks();
	inline const T &Peek(int) const; // n-й элемент от вершины стека
	inline int getStackSize() const;  // получить размер стека
	inline T *getPtr() const;         // получить указатель на стек
	inline int getTop() const;        // получить номер текущего элемента в стеке
	inline void PrintSeries(Stack<T> &);
	inline void sequence(Stack<T> &, Stack<T> &);
};

// реализация методов шаблона класса STack

// конструктор Стека
template <typename T>
Stack<T>::Stack(int maxSize) :
	size(maxSize) // инициализация константы
{
	stackPtr = new T[size]; // выделить память под стек
	top = 0; // инициализируем текущий элемент нулем;
}

// конструктор копирования
template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) :
	size(otherStack.getStackSize()) // инициализация константы
{
	stackPtr = new T[size]; // выделить память под новый стек
	top = otherStack.getTop();

	for (int ix = 0; ix < top; ix++)
		stackPtr[ix] = otherStack.getPtr()[ix];
}

// функция деструктора Стека
template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr; // удаляем стек
}

// функция добавления элемента в стек
template <typename T>
inline void Stack<T>::push(const T &value)
{
	// проверяем размер стека
	assert(top < size); // номер текущего элемента должен быть меньше размера стека

	stackPtr[top++] = value; // помещаем элемент в стек
}

// функция удаления элемента из стека
template <typename T>
inline void Stack<T>::pop()
{
	// проверяем размер стека
	assert(top > 0); // номер текущего элемента должен быть больше 0

	stackPtr[--top]; // удаляем элемент из стека

}

template <typename T>
inline void Stack<T>::Clear()
{
	for (int ix = top - 1; ix >= 0; ix--)
	{
		assert(top > 0); // номер текущего элемента должен быть больше 0

		stackPtr[--top]; // удаляем элемент из стека
	}

}

// функция возвращает n-й элемент от вершины стека
template <class T>
inline const T &Stack<T>::Peek(int nom) const
{
	//
	assert(nom <= top);

	return stackPtr[top - nom]; // вернуть n-й элемент стека
}

// вывод стека на экран
template <typename T>
inline void Stack<T>::printStack()
{
	for (int ix = top - 1; ix >= 0; ix--)
		cout << "|" << setw(4) << stackPtr[ix] << endl;
}

// вернуть размер стека
template <typename T>
inline int Stack<T>::getStackSize() const
{
	return size;
}

// вернуть указатель на стек (для конструктора копирования)
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


// вернуть размер стека
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
		cout << " Скобки расставлены верно" << endl;

	}
	else
	{
		cout << " Скобки расставлены не верно" << endl;

	}

}

template <typename T>
inline void Stack<T>::PrintSeries(Stack<T> & stack)
{
	Stack<double> stackNew(10);
	double ch;

	cout << "Результат: " << endl;
	for (int i = top - 1; i >= 0; i--)
	{
		if (stack.stackPtr[i - 1] <= stack.stackPtr[i])
		{
			stackNew.push(stack.stackPtr[i]); // помещаем элементы в стек
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

	cout << " Результат: " << endl;



	for (int i = top - 1; i >= 0; i--)
	{

		stackNew.push(stack1.stackPtr[i]); // помещаем элементы в стек
		stackNew.push(stack2.stackPtr[i]); // помещаем элементы в стек
	}
	stackNew.sort(stackNew);
}		


#endif // STACK_H