#pragma once
#include <iostream>
#include <sstream>
using namespace std;


template<typename T>
class DLList {
	struct Node {
		T data;
		Node* next;
		Node* prev;
		Node(T data) {
			this->data = data;
			next = nullptr;
			prev = nullptr;
		}
	};
	Node* head;
	Node* tail;
public:
	DLList() {
		head = nullptr;
		tail = nullptr;
	}
	DLList(T arr[], int size, bool reversed) {
		head = tail = nullptr;
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
	~DLList() {
		clear();
	}
	DLList(T arr[], int size) {
		head = tail = nullptr;
		T temp;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - 1; j++) {
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
		if (head!=nullptr)
		{
			Node* newElement = new Node(element);
			newElement->next = head;
			head->prev = newElement;
			head = newElement;
		}
		else
		{
			head = tail = new Node(element);
		}
	}
	void addBefore(Node* whereTo, T element) {
		if (whereTo) {
			if (whereTo->prev) {
				addAfter(whereTo->prev, element);
			}
			else {
				addToHead(element);
			}
		}
	}
	void addAfter(Node* whereTo, T element) {
		if (whereTo) {
			if (whereTo->next) {
				Node* newElement = new Node(element);
				newElement->next = whereTo->next;
				newElement->prev = whereTo;
				whereTo->next->prev = newElement;
				whereTo->next = newElement;
			}
			else {
				Node* newElement = new Node(element);
				newElement->next = whereTo->next;
				newElement->prev = whereTo;
				tail = newElement;
			}
		}
	}

	void deleteBefore(Node* whereTo) {
		deleteNode(whereTo->prev);
	}

	void deleteAfter(Node* whereTo) {
		deleteNode(whereTo->next);
	}

	void deleteNode(Node* node) {
		if (node) {
			if (node->next && node->prev) {
				node->next->prev = node->prev;
				node->prev->next = node->next;
				delete node;
				node = nullptr;
			}
			else if (node->next && !node->prev) {
				node->next->prev = node->prev;
				head = node->next;
				delete node;
				node = nullptr;
			}
			else if (!node->next && node->prev) {
				node->prev->next = node->next;
				tail = node->prev;
				delete node;
				node = nullptr;
			}
			else if (!node->next && !node->prev) {
				head = tail = nullptr;
				delete node;
				node = nullptr;
			}
		}
	}
	void print(bool reversed = false) {
		if (!reversed) {
			Node* temp = head;
			while (temp != nullptr) {
				cout << temp->data << " ";
				temp = temp->next;
			}
		}
		else {
			Node* temp = tail;
			while (temp != nullptr) {
				cout << temp->data << " ";
				temp = temp->prev;
			}
		}
	}

	void clear() {
		while (!isEmpty())
		{
			deleteNode(head);
		}
	}

	bool isEmpty() {
		return head == nullptr;
	}

};