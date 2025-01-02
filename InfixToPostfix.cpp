#include <iostream>
#include <string>
#include "StackList.h"

using namespace std;


bool preor(char s,StackList<char>& stack)//true-вытаскиваем все операторы с большим или равным приоритетом
{
	if (stack.isEmpty())
		return false;
	else if (s == '*' || s == '/')
	{
		if (stack.peek() == '*' || stack.peek() == '/')
			return true;
		else return false;
	}
	else if (s == '+' || s == '-')
	{
		if (stack.peek() == '(')
			return false;
		else return true;
	}
	return false;
}

string InfixToPostfix()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите ф-лу:";
	string str,newStr;
	getline(cin, str);
	StackList<char> stack;
	for (int i = 0;i < (int)str.length();i++ )
	{
		if (str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*' && str[i] != ')' && str[i] != '(')
			newStr += str[i];
		else
		{
			if (str[i] == '(')
				stack.addElem(str[i]);
			else if (str[i] == ')')
			{
				while (!stack.isEmpty() && stack.peek() != '(')
				{
					newStr += stack.peek();
					stack.removeElem();
				}
				stack.removeElem();
			}
			else
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