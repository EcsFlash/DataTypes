#pragma once

template <typename T>

struct BinaryTree
{
	T data;
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

template <typename T>
void initTree(BinaryTree<T>*& root)
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

template <typename T>
bool isEmpty(BinaryTree<T>* root)
{
	return root == nullptr;
}

template <typename T>
T getRootdata(BinaryTree<T>* root)
{
	if (!isEmpty(root))
		return root->data;
}


template <typename T>
void setRootData(BinaryTree<T>* root, T elem)
{
	if (!isEmpty(root))
	{
		root->data = elem;
	}
}


template <typename T>
void clear(BinaryTree<T>*& root)
{
	if (!isEmpty(root))
	{
		clear(root->left);
		clear(root->right);
		delete root;
		root = nullptr;
	}
}

