#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int _data) {
		data = _data;
	}
};

struct ListNode {
	Node* data;
	ListNode* next;
	ListNode(Node* _data) {
		data = _data;
		next = nullptr;
	}
};
ListNode* head = nullptr;

void addToHead(ListNode*& head, Node* root) {
	ListNode* newEl = new ListNode(root);
	newEl->next = head;
	head = newEl;
}

void attachLeft(Node* root, Node* left) {
	root->left = left;
}

void attachRight(Node* root, Node* right) {
	root->right = right;
}

void prefixOrderS(Node* node) {
	if (node) {
		addToHead(head, node);
		prefixOrderS(node->left);
		prefixOrderS(node->left);
	}
}

void prefixOrder(Node* node) {
	if (node) {
		cout << node->data << " ";
		prefixOrder(node->left);
		prefixOrder(node->right);
	}

}
