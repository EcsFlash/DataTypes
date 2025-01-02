#include <iostream>

using namespace std;
template<typename T>
class StackArr
{
	T* mass;
	int size;
	int top;

	void print(int node)
	{
		if (node>-1)
		{
			cout << mass[node] << " ";
			print(node--);
		}

	}

public:
	StackArr(int len = 1)
	{
		size = len;
		mass = new T[size];
		top = -1;
	}

	~StackArr()
	{
		delete[]mass;
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
		else top = -1;
	}

	T peek()
	{
		if(!isEmpty())
			return mass[top];//почему то возвращает 1 если нет элементов
	}

	bool isEmpty()
	{
		if (top < 0)
			return true;
		return false;
	}

	void print()
	{
		print(top);
	}
};