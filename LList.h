#include <iostream>
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
	void addToHead(T element) {
		//Node* temp = head;
		Node* newHead = new Node(element);
		newHead->next = head;
		head = newHead;
	}
	void print() {
		Node* temp = head;
		while(temp != nullptr){
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
};