#pragma once

template<typename T>
class BSTree {
	struct Node {
		T data;
		Node* left;
		Node* right;
		Node(T _data) {
			data = _data;
			left = right = nullptr;
		}
	};
	Node* root;

	void insert(Node*& node, T element) {
		if (!node) {
			node = new Node(element);
		}
		else {
			if (element >= node->data) {
				insert(node->right, element);
			}
			else {
				insert(node->left, element);
			}
		}
	}

	Node*& search(Node*& node, T element) {
		if (node) {
			if (element == node->data) {
				return node;
			}
			else if (element >= node->data)
			{
				return search(node->right, element);
			}
			else {
				return search(node->left, element);
			}
		}
		else {
			return nullptr;
		}
	}

	T successor(Node* node) {
		node = node->left;
		while (node->left || node->right)
		{
			node = node->right;
		}
		T result = node->data;
		delete node;
		node = nullptr;
		return result;
	}

	void prefixTraverse(Node* node) {
		//do smth
		prefixTraverse(node->left);
		prefixTraverse(node->right);
	}

	void postfixTraverse(Node* node) {
		postfixTraverse(node->left);
		postfixTraverse(node->right);
		//do smth
	}

	void infixTraverse(Node* node) {
		infixTraverse(node->left);
		//do smth
		infixTraverse(node->right);
	}
public:
	BSTree() {
		root = nullptr;
	}
	~BSTree() {
		clear();
	}
	bool isEmpty() {
		return root == nullptr;
	}
	void insert(T element) {
		insert(root, element);
	}
	void remove(T element) {
		Node* searchedNode = search(element);
		if (searchedNode) {
			if (searchedNode->left && searchedNode->right) {
				T succ = successor(searchedNode);
				searchedNode->data = succ;
			}
			else if (!searchedNode->left && searchedNode->right) {
				Node* temp = searchedNode;
				searchedNode = searchedNode->right;
				delete temp;
				temp = nullptr;
			}
			else if (searchedNode->left && !searchedNode->right) {
				Node* temp = searchedNode;
				searchedNode = searchedNode->left;
				delete temp;
				temp = nullptr;
			}
			else if (!searchedNode->left && !searchedNode->right) {
				delete searchedNode;
				searchedNode = nullptr;
			}
		}
		
	}
	Node*& search(T element) {
		return search(root, element);
	}

	void prefixTraverse() {
		prefixTraverse(root);
	}

	void postfixTraverse() {
		postfixTraverse(root);
	}

	void infixTraverse() {
		infixTraverse(root);
	}


	bool iterativeSearch(T element) {
		Node* temp = root;
		while (temp) {
			if (temp->data == element) {
				return true;
			}
			else if (element < temp->data) {
				temp = temp->left;
			}
			else if(element >= temp->data){
				temp = temp->right;
			}
		}
		return false;
	}


};