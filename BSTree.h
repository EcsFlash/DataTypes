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
			prefixTraverse(node->left);
			prefixTraverse(node->right);
		}
	}

	void postfixTraverse(Node* node) {
		if (node) {
			postfixTraverse(node->left);
			postfixTraverse(node->right);
			cout << node->data << endl;

		}
	}

	void infixTraverse(Node* node) {
		if (node) {
			infixTraverse(node->left);
			cout << node->data << endl;
			infixTraverse(node->right);
		}
	}
	void remove(Node*& node, T element) {
		if (node) {
			if (element < node->data) {
				remove(node->left, element);
			}
			else if (element > node->data) {
				remove(node->right, element);
			}
			else if (element == node->data) {
				if (node->left && node->right) {
					T succ = successor(node->left);
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
		else {
			throw invalid_argument("failed to remove");
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
	void remove2(T element) {
		Node* node = search(root, element);
		if (node->left && node->right) {
			T succ = successor(node->left);
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
	void clear() {
		clear(root);
	}

};