#pragma once
#include "InfixToPostfix.cpp"
#include "Calculate_formula.cpp"
#include "HashArr.h"
#include "Item_for_hash.h"
#include "BinaryTree.h"
#include "HashList.h"
#include "BSTree.h"
#include "Tree-formila.h"
#include "FibTree.h"
#include <fstream>
#include "PerfectlyBalancedTree.h"
#include "QueueArr.h"
#include "AVLTree.h"
int main() {
	//ZOVZOVZOV
	//


	//HashTableWithList<Item> hash(100);
	//for (int i = 0; i < 40; i++) {
	//	hash.insert(Item(i, "name"));
	//}
	//hash.print();
	//cout << "#######" << endl;
	//for (int i = 40; i < 80; i++) {
	//	hash.insert(Item(i, "bo4ka"));
	//}
	//hash.print();
	/*HashTable2<Item> hashT(100, 2);
	for (int i = 0; i < 30; i++) {
		hashT.insert(Item(i, "pukpuk"));
	}*/
	////
	//hashT.insert(Item(12, "pukpuk"));
	//hashT.insert(Item(12, "pukpuk"));
	//hashT.print();
	//cout << Calculator_formula();
	/*BinaryTree* root = new BinaryTree(2);

	BinaryTree* rootl = new BinaryTree(3);
	BinaryTree* rootr = new BinaryTree(4);
	attachLeftTree(root, rootl);
	attachRightTree(root, rootr);
	BinaryTree* rootrl = new BinaryTree(5);
	BinaryTree* rootrr = new BinaryTree(6);
	attachLeftTree(rootr, rootrl);
	attachRightTree(rootr, rootrr);
	BinaryTree* rootrrr = new BinaryTree(4);
	BinaryTree* rootrrrl = new BinaryTree(5);
	BinaryTree* rootrrrr = new BinaryTree(6);
	attachRightTree(rootrr, rootrrr);
	attachRightTree(rootrrr, rootrrrr);
	attachLeftTree(rootrrr, rootrrrl);


	print(root);
	cout << endl;
	BinaryTree* root2 = new BinaryTree(4);
	BinaryTree* root2l = new BinaryTree(5);
	BinaryTree* root2r = new BinaryTree(6);
	attachRightTree(root2, root2r);
	attachLeftTree(root2, root2l);
	int* i = new int(0);
	searchAndCount(root, root2, i);
	cout << *i << endl;*/
	//
	//BinaryTree* left =new BinaryTree(4);
	//BinaryTree* right = new BinaryTree(5);
	//BinaryTree* root = nullptr;
	////BinaryTree* root1 = nullptr;
	////	BinaryTree* ttree = new BinaryTree(17);
	////attachLeftSon(ttree, 17);
	//attachLeftSon(left, 18);
	//initTree(3, root, left, right);
	//initTree(root,3);
	//cout << getRootdata(root)<<endl;
	//setRootdata(root, 10);
	/*attachLeftSon(root, 100);
	attachRightSon(right, -10);*/
	//attachLeftTree(right, ttree);
	//attachRightTree(left, ttree);
	//root1 = copyRightSubTree(root);
	//print(root);
	//cout << root->data;.
	//printWidth(root);
	//BSTree<int> tree;
	//tree.insert(1);
	//tree.insert(2);
	//tree.insert(3);
	//tree.insert(4);
	//tree.insert(21);
	//tree.insert(-4);
	//tree.insert(6);
	//tree.insert(-7);
	//tree.remove2(1);
	//tree.infixTraverse();
	////printPrefix()
	/*string input = "(3+4)*5";
	istringstream fin(input);
	TTree formulaTree = createFormula(fin);
	cout << "Дерево в строку: " << printToStr(formulaTree) << endl; 
	cout << "Результат вычисления: " << culcFormula(formulaTree) << endl;
	deleteTree(formulaTree);*/

	//ifstream in("hello.txt");
	//*FibTree A(1, 5);
	//A.PrintTree();*/
	//PBTree<int> pbtree( 21, in);
	//pbtree.print();
	//
	//

	//QueueArr<int> qu(3);
	//qu.enque(1);
	//qu.enque(1);
	//qu.enque(1);
	//qu.enque(1);
	//qu.deque();
	//qu.print();
	//cout << endl;
	//qu.deque();
	//cout << "#1  ";
	//qu.print();
	//cout << endl;
	//qu.deque();
	//cout << "#2  ";
	//qu.print();
	//cout << endl;
	//qu.deque();
	//cout << "#3  ";
	//qu.print();
	//cout << endl;
	//qu.deque();

	//qu.print();
	////

	AVLTree<int> tree;
	tree.Insert(5);
	tree.Insert(4);
	tree.Insert(3);
	tree.Insert(2);
	tree.Insert(9);
	tree.Insert(1);

	tree.Insert(32);
	tree.Insert(21);
	tree.Insert(25);
	tree.Insert(162);
	tree.Insert(162);
	tree.Insert(162);
	tree.Insert(162);
	tree.iterativeDFS();
	////tree.infixOrder();
	//tree.prefixOrder();
	//

	/*TreeNode* root = createFormula(in);
	prefixFormulaOrder(root);
	cout << printToStr(root) << endl;

	cout << culcFormula(root) << endl;*/
	//
	//
}
