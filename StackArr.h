//#include <iostream>
//
//using namespace std;
//template<typename T>
//class StackArr
//{
//	T* mass;
//	int size;
//	int top;
//
//	void print(int node)
//	{
//		if (!isEmpty())
//		{
//			cout << mass[top] << " ";
//			print(top++		);
//		}
//
//	}
//
//public:
//	StackArr(int len=5)
//	{
//		size = len;
//		mass = new T[size];
//		top = -1;
//	}
//
//	~StackArr()
//	{
//		delete[]mass;
//	}
//
//	void clear()
//	{
//		while (!isEmpty())
//			removeElem();
//	}
//
//	void addElem(T element)
//	{
//		if(top>=size)
//	}
//
//	void removeElem()
//	{
//		if (!isEmpty())
//		{
//			Node* removeElem = top;
//			top = top->next;
//			delete removeElem;
//			removeElem = nullptr;
//		}
//	}
//
//	T peek()
//	{
//		return top->data;
//	}
//
//	bool isEmpty()
//	{
//		if (size > 0)
//			return false;
//		return true;
//	}
//
//	void print()
//	{
//		print(top);
//	}
//};