#pragma once
#include <iostream>
#include <sstream>
using namespace std;


template<typename T>
class LList {
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
	LList() {
		head = nullptr;
	}
	LList(T arr[], int size, bool reversed) {
		if (!reversed) {
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
	~LList() {
		clear();
	}
	LList(T arr[], int size) {
		T temp;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size-1; j++) {
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
		//Node* temp = head;
		Node* newHead = new Node(element);
		newHead->next = head;
		head = newHead;
	}
	
	void clear() {
		while (!isEmpty())
		{
			deleteFirst();
		}
	}
	bool isEmpty() {
		return head == nullptr;
	}
	void deleteFirst() {
		if (!isEmpty()) {
			Node* temp = head->next;
			delete head;
			head = temp;
		}
	}
	void deleteAfter(Node* whereTo) {
		if (whereTo) {
			Node* temp = whereTo->next;
			if (temp) {
				whereTo->next = whereTo->next->next;
				delete temp;
			}
		}
	}
	void addAfter(Node* whereTo, T element) {
		if (whereTo) {
			Node* newElement = new Node(element);
			newElement->next = whereTo->next;
			whereTo->next = newElement;
		}
	}

	void print() 
	{
		print(head);
	}

	void println() 
	{
		Node* temp = head;
		while (temp) 
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	T sum() 
	{
		return sum(head, 0);
	}
};