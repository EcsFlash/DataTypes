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
			for (int i = size; i >= 0; i--) {
				addToHead(arr[i]);
			}
		}
	}
	void extendSorted(T arr[], int size) {
		int temp;
		for (int i = 0; i < size; i++) {
			for (int j = i; j < size-1; j++) {
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
	~LList() {
		clear();
	}
	void addToHead(T element) {
		//Node* temp = head;
		Node* newHead = new Node(element);
		newHead->next = head;
		head = newHead;
	}
	string toString() const {
		stringstream result;
		Node* temp = head;
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
	friend ostream& operator<<(ostream& os, const LList& list) {
		return os << list.toString();
	}
};