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
int main() {
	//ZOVZOVZOV
	//
	/*HashTable2<Item> hashT(100, 2);
	for (int i = 0; i < 30; i++) {
		hashT.insert(Item(i, "pukpuk"));
	}*/
	////
	//hashT.insert(Item(12, "pukpuk"));
	//hashT.insert(Item(12, "pukpuk"));
	//hashT.print();
	//cout << Calculator_formula();

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
	cout << "������ � ������: " << printToStr(formulaTree) << endl; 
	cout << "��������� ����������: " << culcFormula(formulaTree) << endl;
	deleteTree(formulaTree);*/

	//ifstream in("hello.txt");
	//*FibTree A(1, 5);
	//A.PrintTree();*/
	//PBTree<int> pbtree( 21, in);
	//pbtree.print();
	//
	//

	QueueArr<int> qu(3);
	qu.enque(1);
	qu.enque(1);
	qu.print();
	cout << endl;
	qu.enque(1);
	qu.print();
	cout << endl;
	qu.enque(1);
	qu.print();
	cout << endl;
	qu.deque();
	qu.print();
	cout << endl;
	cout << qu.peek() << endl;
	//
}
