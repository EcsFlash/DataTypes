#include "InfixToPostfix.cpp"
#include "StackList.h"
#include <string>
using namespace std;

void summa(StackList<char>& stackOperator,StackList<int>& stackOperand)
{
	int a = stackOperand.peek();
	stackOperand.removeElem();
	int b = stackOperand.peek();
	stackOperand.removeElem();

	char p = stackOperator.peek();
	stackOperator.removeElem();

	int result = 0;
	switch (p) {
	case '+': result = a + b; break;
	case '-': result = a - b; break;
	case '*': result = a * b; break;
	case '/': result = a / b; break;
	}
	stackOperand.addElem(result);
}


inline int Calculator_formula()//предполагаем, что подается заведома верная строка(иначе можно писать до посинения)
{
	StackList<char> stackOperator;
	StackList<int> stackOperand;
	string str;
	getline(cin, str);
	str += " ";
	int s = 0;
	string x;
	for (int i = 0;i < (int)str.length()-1;i++)
	{
		
		if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/')
		{
			if (str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == ' ')
				stackOperand.addElem((int)str[i]);
			else
			{
				x += str[i];
				if (str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == ' ')
				{
					stackOperand.addElem((int)x.c_str());
					x = " ";
				}
			}
		}
		else
		{
			if (str[i] == '(' || str[i])
				stackOperator.addElem(str[i]);
			else if (str[i] == ')')
			{
				while (!stackOperator.isEmpty() && stackOperator.peek() != '(')
				{

					summa(stackOperator, stackOperand);
					///*newStr += stack.peek();
					//stackOperator.removeElem();*/
					//int sum = stackOperand.peek();
					//stackOperand.removeElem();
					//switch (stackOperator.peek())
					//{
					//case('+'):
					//	sum += stackOperand.peek();
					//	stackOperand.removeElem();
					//	break;
					//case('-'):
					//	sum -= stackOperand.peek();
					//	stackOperand.removeElem();
					//	break;
					//case('*'):
					//	sum *= stackOperand.peek();
					//	stackOperand.removeElem();
					//	break;
					//case('/'):
					//	sum /= stackOperand.peek();
					//	stackOperand.removeElem();
					//	break;
					//}
					//stackOperand.addElem(sum);
				}
				stackOperator.removeElem();
			}
			else 
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
	
		/*if (str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*') {
			stack.addElem(str[i] - '0');
		}
		else if(!stack.isEmpty())
		{
			int sum = stack.peek();
			stack.removeElem();
			switch (str[i])
			{
			case('+'):
				sum += stack.peek();
				stack.removeElem();
				break;
			case('-'):
				sum -= stack.peek();
				stack.removeElem();
				break;
			case('*'):
				sum *= stack.peek();
				stack.removeElem();
				break;
			case('/'):
				sum /= stack.peek();
				stack.removeElem();
				break;
			}
			stack.addElem(sum);
		}*/
	}
	while (!stackOperator.isEmpty())
	{
		summa(stackOperator, stackOperand);
	}
	return stackOperand.peek();
}