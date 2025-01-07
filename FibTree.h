#pragma once
#include <iostream>
using namespace std;
#pragma once

class FibTree{
private:
	struct Node
	{
		int   data;
		Node* left;
		Node* right;
		Node() {
			data = 0;
			left = right = nullptr;
		}
	};
	Node* root; //”казатель на корень дерева.
	void PrintTree(Node* W, int l) {
		int i;

		if (W != nullptr)
		{
			PrintTree(W->right, l + 1);
			for (i = 1; i <= l; i++) cout << "   ";
			cout << W->data << endl;
			PrintTree(W->left, l + 1);
		}
	}

	void FibonTree1(int k, Node*& node) {
		if (k == 0)  node = nullptr;
		else
			if (k == 1)
			{
				node = new Node();
			}
			else
			{
				node = new Node();
				FibonTree1(k - 1, node->left);
				FibonTree1(k - 2, node->right);
			}
	}

	void FibonTree2(Node*& node, int& i) {
		if (node)
		{
			FibonTree2(node->left, i);
			node->data = i;
			i++;
			FibonTree2(node->right, i);
		}
	}
public:
	FibTree() {
		root = nullptr; 
	};

	FibTree(int i, int k) {
		root = nullptr;
		FibonTree1(k, root);
		FibonTree2(root, i);
	}

	Node* GetTree() { 
		return root; 
	};

	Node* GetTree1() { 
		return root; 
	};

	void PrintTree() {
		PrintTree(root, 0);
	}
};

