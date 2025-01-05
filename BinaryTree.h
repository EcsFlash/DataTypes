#pragma once


struct BinaryTree
{
	int  data;
	BinaryTree* left, * right;

	BinaryTree(T elem)
	{
		data = elem;
		left = right = nullptr;
	}

	BinaryTree(T elem, BinaryTree* leftTree, BinaryTree* rightTree)
	{
		data = elem;
		left = leftTree;
		right = rightTree;
	}
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
//template <typename T>
//void initTree(T elem,BinaryTree<T>*& root,BinaryTree<T>* rootLeft,BinaryTree<T>* rootRight)
//{
//	root = new BinaryTree<T>;
//	root->data = elem;
//	root->left = rootLeft;
//	root->right = rootRight;
//}


bool isEmpty(BinaryTree* root)
{
	return root == nullptr;
}


int getRootdata(BinaryTree* root)
{
	if (!isEmpty(root))
		return root->data;
}


void setRottdata(BinaryTree* root, T elem)
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

