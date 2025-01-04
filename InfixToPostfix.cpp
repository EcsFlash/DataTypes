#pragma once
#include <iostream>
#include <string>
#include "StackList.h"
using namespace std;


inline bool preor(char s,StackList<char>& stack)//true-вытаскиваем все операторы с большим или равным приоритетом
{
	if (stack.isEmpty())
		return false;
	if ((s == '*' || s == '/') && (stack.peek() == '*' || stack.peek() == '/'))
		return true;
	if ((s == '+' || s == '-') && (stack.peek() == '+' || stack.peek() == '-' || stack.peek() == '*' || stack.peek() == '/'))
		return true;
	return false;
}

inline string InfixToPostfix()
{
	//(a+b)*(c+d)
	
	setlocale(LC_ALL, "ru");
	cout << "Введите ф-лу:";
	string str,newStr;
	getline(cin, str);
	StackList<char> stack;
	for (int i = 0;i < (int)str.length();i++ )
	{
		if (str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*' && str[i] != ')' && str[i] != '(') //only chars for ex.: a, b, etc
			newStr += str[i];
		else
		{
			if (str[i] == '(') {
				stack.addElem(str[i]);
			}
			else if (str[i] == ')')
			{
				while (!stack.isEmpty() && stack.peek() != '(')
				{
					newStr += stack.peek();
					stack.removeElem();
				}
				stack.removeElem();
			}
			else //only arifmetic operators
			{
				while (!stack.isEmpty() && preor(str[i],stack))
				{
					newStr += stack.peek();
					stack.removeElem();
				}
				stack.addElem(str[i]);
			}
		}
	}
	while (!stack.isEmpty())
	{
		newStr += stack.peek();
		stack.removeElem();
	}
	return newStr;
}