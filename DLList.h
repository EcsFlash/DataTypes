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
public:
	DLList() {
		head = nullptr;
	}
	DLList(T arr[], int size, bool reversed) {
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
	~DLList() {
		clear();
	}
	void extendSorted(T arr[], int size) {
		int temp;
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
		Node* newElement = new Node(element);
		newElement->next = head;
		head = newElement;
	}
};