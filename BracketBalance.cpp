#include "StackList.h"
#include <iostream>
#include <string>

using namespace std;

bool BracketBalance()
{
	setlocale(LC_ALL, "ru");
	cout << "¬ведите строку:";
	string str, newStr;
	getline(cin, str);
	StackList<char> stack;
	for (int i = 0;i < (int)str.length();i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			stack.addElem(str[i]);

		else if (str[i] == ')' || str[i] == '}' || str[i]==']')
		{
			if (stack.isEmpty())
				return false;

			else if ((stack.peek() == '(' && str[i] == ')') ||
				(stack.peek() == '[' && str[i] == ']') || 
				(stack.peek() == '{' && str[i] == '}'))
				stack.removeElem();

			else return false;
		}
	}
	return stack.isEmpty();

}