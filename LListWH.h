#pragma once
#include <iostream>
#include <sstream>
using namespace std;


template<typename T>
class LListWH {
	struct Node {
		T data;
		Node* next;
		Node(T data) {
			this->data = data;
			next = nullptr;
		}
	};
	Node* head;
	void print(Node* node) {
		if (node) {
			cout << node->data << " ";
			print(node->next);
		}
	}
	T sum(Node* node, T currentSum) {
		if (node) {
			return sum(node->next, currentSum + node->data);
		}
		else {
			return currentSum;
		}
	}
public:
	LListWH() {
		head = new Node(0);
	}
	LListWH(T arr[], int size, bool reversed) {
		head = new Node(0);
		if (reversed) {
			for (int i = 0; i < size; i++) {
				addToHead(arr[i]);
			}
		}
		else {
			for (int i = size-1; i >= 0; i--) {
				addToHead(arr[i]);
			}
		}
	}
	~LListWH() {
		clear();
		delete head;
		head = nullptr;
	}
	LListWH(T arr[], int size) {
		head = new Node(0);
		T temp;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (arr[i] < arr[j]) {
					temp = arr[j];
					arr[j] = arr[i];
					arr[i] = temp;
				}
			}
		}
		for (int i = 0; i < size; i++) {
			addToHead(arr[i]);
		}
	}

	void addToHead(T element) {
		Node* newHead = new Node(element);
		newHead->next = head->next;
		head->next = newHead;
	}

	void clear() {
		while (!isEmpty())
		{
			deleteFirst();
		}
	}

	bool isEmpty() 
	{
		return head->next == nullptr;
	}

	void deleteFirst() {
		if (!isEmpty()) {
			Node* temp = head->next->next;
			delete head->next;
			head->next = temp;
		}
	}

	void deleteAfter(Node* whereTo) 
	{
		if (whereTo) {
			Node* temp = whereTo->next;
			if (temp) {
				whereTo->next = whereTo->next->next;
				delete temp;
			}
		}
	}

	void addAfter(Node* whereTo, T element) 
	{
		if (whereTo) {
			Node* newElement = new Node(element);
			newElement->next = whereTo->next;
			whereTo->next = newElement;
		}
	}
	void println() {
		Node* temp = head->next;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	
	void print() 
	{
		print(head->next);
	}

	T sum() 
	{
		return sum(head->next, 0);
	}
};