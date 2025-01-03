#include "InfixToPostfix.cpp"
#include "StackList.h"
using namespace std;

inline int Calculator_formula()//предполагаем, что подается заведома верная строка(иначе можно писать до посинения)
{
	StackList<int> stack;
	string str = InfixToPostfix();
	for (int i = 0;i < (int)str.length();i++)
	{
		if (str[i] != '+' && str[i] != '-' && str[i] != '/' && str[i] != '*')
			stack.addElem(str[i] - '0');
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
		}
	}
	return stack.peek();
}