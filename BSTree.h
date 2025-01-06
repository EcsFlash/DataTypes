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

	T successor(Node*& node) {
		if (node->right) {
			return successor(node->right);
		}
		else {
			T result = node->data;
			Node* temp = node;
			node = node->left;
			delete temp;
			temp = nullptr;
			return result;
		}
	}

	void prefixTraverse(Node* node) {
		if (node) {
			cout << node->data << endl;
			//do smth
			prefixTraverse(node->left);
			prefixTraverse(node->right);
		}
	}

	void postfixTraverse(Node* node) {
		if (node) {
			postfixTraverse(node->left);
			postfixTraverse(node->right);
			//do smth
		}
	}

	void infixTraverse(Node* node) {
		if (node) {
			infixTraverse(node->left);
			//do smth
			infixTraverse(node->right);
		}
	}
	void remove(Node*& node, T element) {
		if (element < node->data) {
			remove(node->left, element);
		}
		else if (element > node->data) {
			remove(node->right, element);
		}
		else if (element == node->data) {
			if (node->left && node->right) {
				T succ = successor(node);
				node->data = succ;
			}
			else if (!node->left && node->right) {
				Node* temp = node;
				node = node->right;
				delete temp;
				temp = nullptr;
			}
			else if (node->left && !node->right) {
				Node* temp = node;
				node = node->left;
				delete temp;
				temp = nullptr;
			}
			else if (!node->left && !node->right) {
				delete node;
				node = nullptr;
			}
		}

	}
public:
	BSTree() {
		root = nullptr;
	}
	~BSTree() {
		//clear();
	}
	bool isEmpty() {
		return root == nullptr;
	}
	void insert(T element) {
		insert(root, element);
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

	void remove(T element) {
		remove(root, element);
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