#pragma once
#include <iostream>
using namespace std;

template<typename T>
class StackList
{
	struct Node
	{
		T data;
		Node* next;

		Node(T data)
		{
			this->data = data;
			next = nullptr;
		}
	};

	Node* top;

	void print(Node* node)
	{
		if (node)
		{
			cout << node->data<<" ";
			print(node->next);
		}
		
	}

public:
	StackList()
	{
		top = nullptr;
	}

	~StackList()
	{
		clear();
	}

	void clear()
	{
		while (!isEmpty())
			removeElem();
	}

	void addElem(T element)
	{
		Node* newElement = new Node(element);
		if (isEmpty())
		{
			top = newElement;
		}
		else
		{
			newElement->next = top;
			top = newElement;
		}
		
	}

	void removeElem()
	{
		if (!isEmpty())
		{
			Node* removeElem = top;
			top = top->next;
			delete removeElem;
			removeElem = nullptr;
		}
	}

	T peek()
	{
		if(!isEmpty())
			return top->data;
	}

	bool isEmpty()
	{
		if(!isEmpty())
			return top == nullptr;
		throw runtime_error("Stack is empty!");
	}

	void print()
	{
		print(top);
	}
};