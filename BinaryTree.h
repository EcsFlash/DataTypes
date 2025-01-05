#pragma once
#include <iostream>

using namespace std;

struct BinaryTree
{
	int  data;
	BinaryTree* left, * right;

	BinaryTree(int  elem)
	{
		data = elem;
		left = right = nullptr;
	}
};


inline void initTree(BinaryTree*& root)
{
	root = nullptr;
}

inline void initTree(int elem,BinaryTree*& root,BinaryTree* rootLeft,BinaryTree* rootRight)
{
	root = new BinaryTree(elem);
	root->left = rootLeft;
	root->right = rootRight;
}


inline bool isEmpty(BinaryTree* root)
{
	return root == nullptr;
}


inline int getRootdata(BinaryTree* root)
{
	if (!isEmpty(root))
		return root->data;
}


inline void setRootdata(BinaryTree* root, int elem)
{
	if (!isEmpty(root))
	{
		root->data = elem;
	}
}


inline void clear(BinaryTree*& root)
{
	if (!isEmpty(root))
	{
		clear(root->left);
		clear(root->right);
		delete root;
		root = nullptr;
	}
}

inline bool attachLeftSon(BinaryTree* root, int elem) {
	if (!isEmpty(root)) 
	{
		if (isEmpty(root->left)) 
		{
			root->left = new BinaryTree(elem);
			return true;
		}
		else return false;
	}
	return false;
}

inline bool attachLeftTree(BinaryTree* root, BinaryTree* leftSubTree) 
{
	if (!isEmpty(root)) 
	{
		if (isEmpty(root->left)) 
		{
			root->left = leftSubTree;
			return true;
		}
		else return false;
	}
	return false;
}

inline bool attachRightSon(BinaryTree* root, int elem)
{
	if (!isEmpty(root))
	{
		if (isEmpty(root->right)) 
		{
			root->left = new BinaryTree(elem);
			return true;
		}
		else return false;
	}
	return false;
}

inline bool attachRightTree(BinaryTree* root, BinaryTree* rightSubTree) 
{
	if (!isEmpty(root)) 
	{
		if (isEmpty(root->right)) 
		{
			root->right = rightSubTree;
			return true;
		}
		else return false;
	}
	return false;
}

inline BinaryTree* copyTree(BinaryTree* root) {
	if (!isEmpty(root)) {
		BinaryTree* newRoot = new BinaryTree(root->data);
		newRoot->left = copyTree(root->left);
		newRoot->right = copyTree(root->right);
		return newRoot;
	}
	else {
		return nullptr;
	}
}

inline BinaryTree*& detachLeftSubTree(BinaryTree* root)
{
	BinaryTree* leftSubTree = root->left;
	root->left = nullptr;
	return leftSubTree;
}

inline BinaryTree*& detachRightSubTree(BinaryTree* root)
{
	BinaryTree *rightSubTree = root->right;
	root->right = nullptr;
	return rightSubTree;
}

inline BinaryTree*& copyLeftSubTree(BinaryTree* root) 
{
	if (!isEmpty(root)) 
	{
		BinaryTree* leftSubTree = copyTree(root->left);
		return leftSubTree;
	}
}

inline BinaryTree*& copyRightSubTree(BinaryTree* root) {
	if (!isEmpty(root))
	{
		BinaryTree *rightSubTree = copyTree(root->left);
		return rightSubTree;
	}
}

inline void print(BinaryTree* root)
{
	if (!isEmpty(root))
	{
		cout << root->data << " ";
		if (!isEmpty(root->left))
			print(root->left);
		if (!isEmpty(root->right))
			print(root->right);
	}
	
}

inline void printS(BinaryTree* root)
{
	if (!isEmpty(root))
	{
		if (!isEmpty(root->left))
			printS(root->left);
		cout << root->data << " ";
		if (!isEmpty(root->right))
			printS(root->right);
	}
}

inline void printOb(BinaryTree* root)
{
	if (!isEmpty(root))
	{
		if (!isEmpty(root->left))
			printOb(root->left);
		if (!isEmpty(root->right))
			printS(root->right);
		cout << root->data << " ";
	}
}