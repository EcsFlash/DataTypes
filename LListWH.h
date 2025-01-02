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
		if (!reversed) {
			for (int i = 0; i < size; i++) {
				addToHead(arr[i]);
			}
		}
		else {
			for (int i = size; i >= 0; i--) {
				addToHead(arr[i]);
			}
		}
	}
	~LListWH() {
		clear();
	}
	LListWH(T arr[], int size) {
		T temp;
		for (int i = 0; i < size; i++) {
			for (int j = i; j < size - 1; j++) {
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
	string toString() const {
		stringstream result;
		Node* temp = head->next;
		while (temp != nullptr) {
			result << temp->data << " ";
			temp = temp->next;
		}
		return result.str();
	}
	void clear() {
		while (!isEmpty())
		{
			deleteFirst();
		}
	}
	bool isEmpty() {
		return head->next == nullptr;
	}
	void deleteFirst() {
		if (!isEmpty()) {
			Node* temp = head->next->next;
			delete head->next;
			head->next = temp;
		}
	}
	void deleteAfter(Node* whereTo) {
		if (!isEmpty() && whereTo) {
			Node* temp = whereTo->next;
			if (temp) {
				whereTo->next = whereTo->next->next;
				delete temp;
			}
		}
	}
	void addAfter(Node* whereTo, T element) {
		if (!isEmpty() && whereTo) {
			Node* newElement = new Node(element);
			newElement->next = whereTo->next;
			whereTo->next = newElement;
		}
	}
	friend ostream& operator<<(ostream& os, const LListWH& list) {
		return os << list.toString();
	}
	void print() {
		print(head->next);
	}
	T sum() {
		return sum(head->next, 0);
	}
};