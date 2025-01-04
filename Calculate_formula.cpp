#include "InfixToPostfix.cpp"
#include "StackList.h"
#include <string>
using namespace std;

void sum(StackList<char>& stackOperator,StackList<int>& stackOperand)
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
	for (int i = 0;i < (int)str.length()-1;i++)
	{
		if (isdigit(str[i]))
			x += str[i];
		//else
		//{
		//	if (!x.empty())
		//	{
		//		stackOperand.addElem(stoi(x));
		//		x.clear();
		//	}
		//}
		////if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/')
		////{
		////	if (str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == ' ')
		////	{
		////		stackOperand.addElem((int)str[i]);
		////		stackOperand.print();cout << endl;
		////	}
		////	else
		////	{
		////		if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/') {
		////			x += str[i];  // Собираем цифры в строку
		////		}
		////		else {
		////			if (!x.empty()) {
		////				stackOperand.addElem(stoi(x));  // Преобразуем строку в целое число
		////				x.clear();  // Очищаем строку для следующего числа
		////			}
		////		}
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
				while (!stackOperator.isEmpty() && stackOperator.peek() != '(')
				{

					sum(stackOperator, stackOperand);
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
					sum(stackOperator, stackOperand);
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
		sum(stackOperator, stackOperand);
	}
	return stackOperand.peek();
}