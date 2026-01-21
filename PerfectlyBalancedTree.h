#pragma once
#include <iostream>
#include <fstream>
using namespace std;
template<typename T>
class PBTree {
	struct Node {
		T data;
		Node* left;
		Node* right;
		Node(T _data) {
			data = _data;
			left=right=nullptr;
		}
	};

	Node* root;
	void createBalancedTree(Node*& node, int n, ifstream& f) 
	{
		if (n > 0)
		{
			int elem;
			f >> elem;
			cout << elem << endl;
			node = new Node(elem);
			createBalancedTree(node->left, n / 2, f);
			createBalancedTree(node->right, n - (n/2) - 1, f);
			
		}
	}
	void createBalancedTree(Node*& node, int* arr, int start, int end) {
	    if (start > end) {
	        return nullptr;
	    }
	
	    int mid = (start + end) / 2;
	    node = new Node(arr[mid]);
	
	    createBalancedTree(node->left, arr, start, mid - 1);
	    createBalancedTree(node->right, arr, mid + 1, end);

	}
	void print(Node* node) {
		if (node) {
			cout << node->data << " ";
			print(node->left);
			print(node->right);
		}
	}
public:
	PBTree(int n, ifstream& f) {
		root = nullptr;
		createBalancedTree(root, n, f);
	}

	void print() {
		print(root);
	}
	
};
