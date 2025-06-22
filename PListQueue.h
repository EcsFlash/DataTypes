#pragma once


#pragma once
#include <iostream>
#include <sstream>
using namespace std;



class PListQueue {
	struct Elem {
		int priority;
		string value;
	};
	struct Node {
		Elem data;
		Node* next;
		Node(int p, string v) {
			this->data = Elem{ p,v };
			next = nullptr;
		}
	};
	Node* head;
	void print(Node* node) {
		if (node) {
			cout << node->data.value << " ";
			print(node->next);
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
	void addAfter(Node* whereTo, int p, string v) {
		if (whereTo) {
			Node* newElement = new Node(p, v);
			newElement->next = whereTo->next;
			whereTo->next = newElement;
		}
	}
	void addToHead(int p, string v) {
		Node* newHead = new Node(p, v);
		newHead->next = head;
		head = newHead;
	}
	void deleteFirst() {
		if (!isEmpty()) {
			Node* temp = head->next;
			delete head;
			head = temp;
		}
	}
public:
	PListQueue() {
		head = nullptr;
	}
	~PListQueue() {
		clear();
	}
	

	void Push(int p, string v) {
		
		if (!isEmpty()) {
			if (p > head->data.priority) {
				addToHead(p, v);
			}
			else {
				Node* temp = head;
				while (temp->next && temp->next->data.priority > p) {
					temp = temp->next;
				};
				addAfter(temp, p, v);
			}
			
		}
		else {
			addToHead(p, v);
		}
	}

	string Pop() {
		if (!isEmpty()) {
			string result = head->data.value;
			deleteFirst();
		}
		else {
			throw "no mama";
		}
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
	
	
	void print()
	{
		print(head);
	}

	void println()
	{
		Node* temp = head;
		while (temp)
		{
			cout << temp->data.value << " ";
			temp = temp->next;
		}
	}

	
};