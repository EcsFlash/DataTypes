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

	/*BinaryTree(T elem, BinaryTree* leftTree, BinaryTree* rightTree)
	{
		data = elem;
		left = leftTree;
		right = rightTree;
	}*/
};


void initTree(BinaryTree*& root)
{
	root = nullptr;
}

//template <typename T>
//void initTree(BinaryTree<T>*& root,T elem)
//{
//	//root = new BinaryTree(elem);
//	root = new BinaryTree<T>;
//	root->data = elem;
//	root->left = nullptr;
//	root->right = nullptr;
//}
//

void initTree(int elem,BinaryTree*& root,BinaryTree* rootLeft,BinaryTree* rootRight)
{
	root = new BinaryTree(elem);
	root->left = rootLeft;
	root->right = rootRight;
}


bool isEmpty(BinaryTree* root)
{
	return root == nullptr;
}


int getRootdata(BinaryTree* root)
{
	if (!isEmpty(root))
		return root->data;
}


void setRootdata(BinaryTree* root, int elem)
{
	if (!isEmpty(root))
	{
		root->data = elem;
	}
}


void clear(BinaryTree*& root)
{
	if (!isEmpty(root))
	{
		clear(root->left);
		clear(root->right);
		delete root;
		root = nullptr;
	}
}

bool attachLeftSon(BinaryTree* root, int elem) {
	if (!isEmpty(root)) 
	{
		if (isEmpty(root->left)) 
		{
			root->left = new BinaryTree(elem);
			root->left->left = nullptr;
			root->left->right = nullptr;
			return true;
		}
		else return false;
	}
	return false;
}
bool attachLeftTree(BinaryTree* root, BinaryTree* leftSubTree) 
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
bool attachRightSon(BinaryTree* root, int elem)
{
	if (!isEmpty(root))
	{
		if (isEmpty(root->right)) 
		{
			root->left = new BinaryTree(elem);
			root->left->left = nullptr;
			root->left->right = nullptr;
			return true;
		}
		else return false;
	}
	return false;
}

bool attachRightTree(BinaryTree* root, BinaryTree* rightSubTree) 
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

BinaryTree* copyTree(BinaryTree* root) {
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

BinaryTree*& detachLeftSubTree(BinaryTree* root)
{
	BinaryTree* leftSubTree = root->left;
	root->left = nullptr;
	return leftSubTree;
}

BinaryTree*& detachRightSubTree(BinaryTree* root)
{
	BinaryTree *rightSubTree = root->right;
	root->right = nullptr;
	return rightSubTree;
}

BinaryTree*& copyLeftSubTree(BinaryTree* root) 
{
	if (!isEmpty(root)) 
	{
		BinaryTree* leftSubTree = copyTree(root->left);
		return leftSubTree;
	}
}
BinaryTree*& copyRightSubTree(BinaryTree* root) {
	if (!isEmpty(root))
	{
		BinaryTree *rightSubTree = copyTree(root->left);
		return rightSubTree;
	}
}



void print(BinaryTree* root)
{
	cout << root->data << " ";
	print(root->left);
	print(root->right);
}