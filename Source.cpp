#pragma once
#include "InfixToPostfix.cpp"
#include "Calculate_formula.cpp"
#include "HashArr.h"
#include "Item_for_hash.h"//
#include "BinaryTree.h"
int main() {
	//HashTable2<Item> hashT(100, 0);
	////for (int i = 0; i < 70; i++) {
	////	hashT.insert(Item(i, "pukpuk"));
	////}
	////
	//hashT.insert(Item(12, "pukpuk"));
	//hashT.insert(Item(12, "pukpuk"));
	//hashT.print();
	//cout << Calculator_formula();

	BinaryTree* left =new BinaryTree(4);
	BinaryTree* right = new BinaryTree(5);
	BinaryTree* root = nullptr;
	BinaryTree* root1 = nullptr;
	BinaryTree* ttree = new BinaryTree(17);
	attachLeftSon(ttree, 18);
	initTree(3, root, left, right);
	//initTree(root,3);
	//cout << getRootdata(root)<<endl;
	//setRootdata(root, 10);
	/*attachLeftSon(root, 100);
	attachRightSon(right, -10);*/
	attachLeftTree(right, ttree);
	attachRightTree(left, ttree);
	root1 = copyRightSubTree(root);
	print(root1);
}