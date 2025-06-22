#pragma once
#include <string>
#include <iostream>
using namespace std;

class PTreeQueue {
	struct Elem {
		int priority;
		string value;
	};
	struct Node {
		Elem data;
		Node* left;
		Node* right;
		Node(int p, string v) {
			data = Elem{ p,v };
			left = right = nullptr;
		}
	};
	Node* root;

	void insert(Node*& node, int p, string v) {
		if (!node) {
			node = new Node(p, v);
		}
		else {
			if (p >= node->data.priority) {
				insert(node->right, p, v);
			}
			else {
				insert(node->left, p, v);
			}
		}
	}

	

	Node*& toDelete(Node*& temp) {
		
		if (temp->right) {
			return toDelete(temp->right);
		}
		else {
			return temp;
		}
	}
	void clear(Node*& node) {
		if (node) {
			clear(node->right);
			clear(node->left);
			delete node;
			node = nullptr;
		}
	}
public:
	PTreeQueue() {
		root = nullptr;
	}
	~PTreeQueue() {
		clear();
	}
	bool isEmpty() {
		return root == nullptr;
	}
	void Push(int p, string v) {
		insert(root, p,v);
	}
	
	void clear() {
		clear(root);
	}
	string Pop() {
		if (!isEmpty()) {
			string result;
			Node*& node = toDelete(root);
			result = node->data.value;
			Node* temp = node;
			node = node->left;
			delete temp;
			temp = nullptr;
			return result;
		}
		else {
			throw "no mama";
		}
	}
};