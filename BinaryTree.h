#pragma once
#include <iostream>
#include "QueueList.h"
#include "StackList.h"

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
			root->right = new BinaryTree(elem);
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
		BinaryTree *rightSubTree = copyTree(root->right);
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

inline void printWidth(BinaryTree* root)
{
	if (!isEmpty(root))
	{
		Queue<BinaryTree*> q;
		q.enque(root);
		while (!q.isEmpty())
		{
			BinaryTree* cur = q.peek();
			q.deque();
			cout << cur->data<<" ";
			if (!isEmpty(cur->left))
				q.enque(cur->left);
			if (!isEmpty(cur->right))
				q.enque(cur->right);
		}
	}
}

inline void printDepth(BinaryTree* root)
{
	StackList<BinaryTree*> stack;
	stack.addElem(root);
	bool done = false;
	BinaryTree* cur = root;
	while (!done)
	{
		if (!isEmpty(cur->left))
		{
			stack.addElem(cur->left);
			cur = cur->left;
		}
		
		else if (!stack.isEmpty())
		{
			cout << stack.peek()->data << " ";
			cur = stack.peek();
			//cur->left = nullptr;
			stack.removeElem();

			if (!isEmpty(cur->right))
			{
				stack.addElem(cur->right);
				cur = cur->right;
			}
		}
		else done = true;
	}
}

inline bool compareTree(BinaryTree* root1, BinaryTree* root2) {
	if (!root2) {
		return true;
	}
	else {
		if (root1 && root1->data == root2->data && compareTree(root1->left, root2->left) &&
			compareTree(root1->right, root2->right)) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}
inline void searchAndCount(BinaryTree* root1, BinaryTree* root2, int* i) {
	if (root1 && root2) {
		if (compareTree(root1, root2)) {
			(*i)++;
		}
		searchAndCount(root1->left, root2, i);
		searchAndCount(root1->right, root2, i);
	}
}