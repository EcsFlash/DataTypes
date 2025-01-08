#pragma once
#include <iostream> 
#include <sstream> 
using namespace std;



template <typename T>
class Queue {
private:

	struct Node {
		T data;
		Node* next;
		Node(T elem) : data(elem), next(nullptr) {};
	};
	Node* head;
	Node* tail;
	int count;
public:
	Queue() {
		head = tail = nullptr;
		count = 0;
	}

	void enque(T elem) {
		Node* p = new Node(elem);
		if (!isEmpty()) {
			tail->next = p;
			tail = p;
		}
		else {
			head = tail = p;
		}
		count++;
	}

	void deque() {
		if (!isEmpty()) {
			if (head != tail) {
				Node* p = head;
				head = head->next;
				delete p;
				p = nullptr;
				count--;
			}
			else {
				delete head, tail;
				head = tail = nullptr;
				count = 0;
			}
		}
	}

	Queue(const Queue<T>& other) {
		head = tail = nullptr;
		count = 0;
		Node* temp = other.head;
		while (temp != nullptr) {
			this->enque(temp->data);
			temp = temp->next;
		}
	}



	Queue& operator=(const Queue& other) {
		head = tail = nullptr;
		count = 0;
		Node* temp = other.head;
		while (temp != nullptr) {
			this->enque(temp->data);
			cout << temp->data << endl;
			temp = temp->next;
		}
		return *this;
	}
	~Queue() {
		clear();
	}

	T peek() {
		if (!isEmpty()) {
			return head->data;
		}
	}



	bool isEmpty() {
		return head == nullptr;
	}



	void clear() {
		while (head != nullptr && tail != nullptr) {
			deque();
		}
	}
	friend std::ostream& operator<<(std::ostream& os, const Queue& a) {
		stringstream ss;
		Node* temp = a.head;

		while (temp != nullptr) {
			ss << temp->data;
			temp = temp->next;
		}
		return os << ss.str();
	}
};
