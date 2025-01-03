#include <iostream>

using namespace std;
template<typename T>
class StackArr
{
	T* mass;
	int size;
	int top;

public:
	StackArr(int len = 1)
	{
		size = len;
		mass = new T[size];
		top = -1;
	}

	~StackArr()
	{
		delete[] mass;
	}

	void clear()
	{
		while (!isEmpty())
			removeElem();
	}

	void addElem(T element)
	{
		top++;
		top = top % size;
		mass[top] = element;
	}

	void removeElem()
	{
		if (!isEmpty())
		{
			top--;
		}
	}

	T peek()
	{
		if(!isEmpty())
			return mass[top];

	}

	bool isEmpty()
	{
		if (top < 0)
			return true;
		return false;
	}

	
};