#pragma once
#include <iostream>
#include <string>
#include "StackList.h"
using namespace std;


static bool preor(char s,StackList<char>& stack)//true-����������� ��� ��������� � ������� ��� ������ �����������
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

static string InfixToPostfix()
{
	//(a+b)*(c+d)
	setlocale(LC_ALL, "ru");
	cout << "������� �-��:";
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
				/*while (!stack.isEmpty() && preor(str[i],stack))
				{
					newStr += stack.peek();
					stack.removeElem();
				}*/
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