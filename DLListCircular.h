#pragma once


template<typename T>
class CDLList {
	struct Node
	{
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
public:
	CDLList() {
		head = new Node(0);
		head->next = head;
		head->prev = head;
	}
	CDLList(T arr[],int size, bool reversed) {
		head = new Node(0);
		head->next = head;
		head->prev = head;
		if (reversed) {
			for (int i = 0; i < size; i++) {
				addToHead(arr[i]);
			}
		}
		else {
			for (int i = size - 1; i >= 0; i--) {
				addToHead(arr[i]);
			}
		}
	}
	CDLList(T arr[], int size) {
		cout << "constructor" << endl;
		head = new Node(0);
		head->next = head;
		head->prev = head;
		cout << "constructor" << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - 1; j++) {
				if (arr[j] < arr[i]) {
					T temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
		for (int i = 0; i < size; i++) {
			addToHead(arr[i]);
		}
	}
	~CDLList() {
		clear();
		delete head;
		head = nullptr;
	}
	void clear() {
		while (!isEmpty()) {
			deleteNode(head->next);
		}
	}
	void addToHead(T element) {
		Node* newElement = new Node(element);
		newElement->next = head->next;
		newElement->prev = head;
		head->next->prev = newElement;
		head->next = newElement;
	}

	bool isEmpty() {
		return head->next == head;
	}

	void addAfter(Node* whereTo, T element) {
		if (whereTo) {
			Node* newElement = new Node(element);
			newElement->next = whereTo->next;
			newElement->prev = whereTo;
			whereTo->next->prev = newElement;
			whereTo->next = newElement;
		}
	}
	void addBefore(Node* whereTo, T element) {
		if (whereTo) {
			addAfter(whereTo->prev, element);
		}
	}
	void deleteNode(Node* node) {
		if (node && node != head) {
			node->next->prev = node->prev;
			node->prev->next = node->next;
			delete node;
			node = nullptr;
		}
	}
	void deleteAfter(Node* whereTo) {
		if (whereTo) {
			deleteNode(whereTo->next);
		}
	}
	void deleteBefore(Node* whereTo) {
		if (whereTo) {
			deleteNode(whereTo->prev);
		}
	}
	void print(bool reversed = false) {
		if (!isEmpty()) {
			cout << "in ptint" << endl;
			Node* temp = head;
			if (reversed) {
				temp = temp->prev;
				while (temp != head)
				{
					cout << temp->data << " ";
					temp = temp->prev;
				}
			}
			else {
				temp = temp->next;
				while (temp != head)
				{
					cout << temp->data << " ";
					temp = temp->next;
				}
			}
		}
	}
};