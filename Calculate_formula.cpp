#include "InfixToPostfix.cpp"
#include "StackList.h"
#include <string>
using namespace std;

void summa(StackList<char>& stackOperator,StackList<int>& stackOperand)
{
	int result = stackOperand.peek();
	stackOperand.removeElem();
	

	switch (stackOperator.peek())
	{
	case '+':
		result += stackOperand.peek();
		break;
	case '-':
		result -= stackOperand.peek();
		break;
	case '*':
		result *= stackOperand.peek();
		break;
	case '/':
		result /= stackOperand.peek();
		break;
	}
	stackOperator.removeElem();
	stackOperand.removeElem();

	stackOperand.addElem(result);
}

inline int Calculator_formula()//предполагаем, что подается заведома верная строка(иначе можно писать до посинения)
{
	StackList<char> stackOperator;
	StackList<int> stackOperand;
	string str;
	getline(cin, str);
	int s = 0;
	string x;
	for (int i = 0;i < (int)str.length();i++)
	{
		if (isdigit(str[i]))
			x += str[i];
		else
		{
			if (!x.empty())
			{
				stackOperand.addElem(stoi(x));
				x.clear();
			}
			if (str[i] == '(')
				stackOperator.addElem(str[i]);
			else if (str[i] == ')')
			{
				//while (!stackOperator.isEmpty() && stackOperator.peek() != '(')
				while (stackOperator.peek() != '(')
				{

					summa(stackOperator, stackOperand);
				}
				stackOperator.removeElem();
			}
			else 
			{
				if (!stackOperator.isEmpty())
				{
					while (!stackOperator.isEmpty() && preor(str[i], stackOperator))
					{
						/*newStr += stack.peek();
						stack.removeElem();*/
						summa(stackOperator, stackOperand);
					}
					stackOperator.addElem(str[i]);
				}
				
			}
		}
	}
	if (!x.empty()) 
	{
		stackOperand.addElem(stoi(x));
	}
	while (!stackOperator.isEmpty())
	{
		summa(stackOperator, stackOperand);
	}
	return stackOperand.peek();
}