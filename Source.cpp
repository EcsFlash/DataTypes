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
#include "Map.h"
#include "map"
#include <vector>
#include "SimpleGraph.h"
#include "NotSimpleGraph.cpp"
#include "PArrQueue.h"
#include "PTreeQueue.h"
#include "HPQueue.h"
#include "Heap.h"
#include <cassert>
#include "DisjointSets.h"


int backpack(int index, int W, int w, int cost, int n, vector<pair<int,int>> arr) {
	if (index == n) {
		return cost;
	}
	if (w > W) {
		return 0;
	}
	int c1 = 0;
	if (w + arr[index].first < W) {
		 c1 = backpack(index + 1, W, w + arr[index].first, cost + arr[index].second, n, arr);
	}
	int c2 = backpack(index + 1, W, w, cost, n, arr);
	return max(c1, c2);
}

int appointmets(int index, int n, int** arr, bool* jobs, int cost) {
	if (index == n) {
		return cost;
	}
	int min_cost = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (!jobs[i]) {
			jobs[i] = true;
			int c1 = appointmets(index + 1, n, arr, jobs, cost+arr[index][i]);
			min_cost = min(min_cost, c1);
			jobs[i] = false;
		}
	}
	return min_cost;
}


int main() {
	const int size = 10;
	DSQuickFind ds(size);

	// —ÓÁ‰‡ÂÏ ÏÌÓÊÂÒÚ‚‡
	for (int i = 0; i < size; ++i) {
		ds.makeset(i);
	}
	
	// Œ·˙Â‰ËÌˇÂÏ ÌÂÍÓÚÓ˚Â ÏÌÓÊÂÒÚ‚‡
	ds.unionSets(0, 1);
	ds.unionSets(2, 3);
	ds.unionSets(2, 0);
	ds.unionSets(2, 4);
	ds.unionSets(1, 2);
	ds.unionSets(5, 6);
	ds.unionSets(7, 8);
	ds.unionSets(8, 9);
	//ds.find(1);
	// œÓ‚ÂˇÂÏ ÍÓÂÍÚÌÓÒÚ¸ Ó·˙Â‰ËÌÂÌËÈ
	assert(ds.find(0) == ds.find(1));
	assert(ds.find(1) == ds.find(2));
	assert(ds.find(2) == ds.find(3));
	assert(ds.find(3) == ds.find(4));
	assert(ds.find(5) == ds.find(6));
	assert(ds.find(7) == ds.find(8));
	assert(ds.find(8) == ds.find(9));
	assert(ds.find(0) != ds.find(5));
	assert(ds.find(2) != ds.find(7));

	std::cout << "All tests passed!" << std::endl;

	MaxHeap he;

	he.fromArray(vector<int>{2,6,5,9,7,8,10});


	PHQueue<int> z;

	z.add(1, 3);
	z.add(2, 7);
	z.add(3, 5);
	z.add(4, 8);
	z.add(5, 9);
	z.add(6, 10);
	z.add(7, 11);
	z.add(8, 10);
	z.add(9, 14);
	z.add(10, 10);
	//cout << endl;cout << endl;cout << endl;
	z.add(11, 6);
	//////////
	//
	//

	z.print();
	cout << z.pop2() << endl;
	cout << z.pop2() << endl;
	cout << z.pop2() << endl;
	z.print();
	cout << endl;cout << endl;cout << endl;cout << endl;

	PTreeQueue p;
	p.Push(10, "Hellow10");
	p.Push(20, "Hellow20");
	p.Push(15, "Hellow15");
	cout << p.Pop() << p.Pop() << p.Pop() << endl;
	//PArrQueue q(3);
	////
	//q.Push(11, "Hello");
	//q.Push(10, "world");
	//q.Push(1, "from Yelez");
	//cout << q.Pop() << q.Pop() << endl;
	vector<vector<int>> k = vector<vector<int>>{
		vector<int>{0,15,14,10},
		vector<int>{15,0,20,13},
		vector<int>{14,20,0,16},
		vector<int>{10,13,16,0},
	};
	SimpleGraph s(k);
	NotSimpleGraph gr;
	//gr.AddEdge(1, 2, 15);
	gr.AddEdge(2, 1, 15);

	//gr.AddEdge(1, 3, 14);
	gr.AddEdge(3, 1, 14);

	//gr.AddEdge(1, 4, 10);
	gr.AddEdge(4, 1, 10);

	//gr.AddEdge(2, 4, 13);
	gr.AddEdge(4, 2, 13);

	//gr.AddEdge(3, 4, 16);
	gr.AddEdge(4, 3, 16);

	//gr.AddEdge(2, 3, 20);
	gr.AddEdge(3, 2, 20);
	//
	// //
	cout << gr.naiveTSP(1) << endl;
	cout << gr.TSPJ(1) << endl;
	gr.print();
	cout << "FUCKING BFS:   ";
	gr.fuckingBFS(1);
	cout << "FUCKING DFS:   ";
	//
	gr.fuckingDFS(1);
	/*gr.AddEdge(1, 2, 4);
	gr.AddEdge(1, 3, 4);
	gr.AddEdge(1, 6, 4);
	gr.AddEdge(6, 2, 4);
	gr.AddEdge(1, 4, 4);
	gr.BFS(1);
	gr.RemoveEdge(1, 2);
	gr.RemoveEdge(6, 2);
	gr.BFS(1);*/
	//
	//
	// //
	//s.print();//
	// //
	//s.BFSI(3);

	cout << "TSP STARTS HERE " << endl;
	cout << s.ntsp(0, set<int>{}, 0) << endl;
	cout << s.tspJ(1) << endl;
	//s.DFSR(1);
	//s.DFSR(2);
	//cout << s.countPieces() << endl;
	//ZOVZOVZOV
	//
	//map<char, int> smap;
	//MapLinear<char, int> map;
	//map['g'] = 5;
	//map['l'] = 78;
	//map['u'] = 100;
	//int* a = &map['g']; // ¬Œ“ ›“»Ã» ƒ¬”Ãﬂ —“–Œ ¿Ã» ÃŒ∆ÕŒ ¬«Œ–¬¿“‹ ¬—®
	//map.remove('g');	// “¿  ƒ≈À¿“‹ Õ≈À‹«ﬂ ¬ŒŒ¡Ÿ≈
	//cout << *a << endl;
	//smap['a'] = 99;		//¿, œŒ’”…
	//int* b = &smap['a'];// —“¿Õƒ¿–“Õ”ﬁ Ã¿œ” “Œ∆≈ ÃŒ∆ÕŒ ¬«Œ–¬¿“‹   ’”ﬂÃ —Œ¡¿◊‹»Ã
	//cout << *b << endl; //
	//smap.erase('a');	//
	//cout << *b << endl; //
	//cout << smap['c'] << endl;
	///*int* a = &map['g'];
	//cout << a << endl;*/
	////map.remove('l');
	//map.print();
	//
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
	cout << "ƒÂÂ‚Ó ‚ ÒÚÓÍÛ: " << printToStr(formulaTree) << endl; 
	cout << "–ÂÁÛÎ¸Ú‡Ú ‚˚˜ËÒÎÂÌËˇ: " << culcFormula(formulaTree) << endl;
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

	//AVLTree<int> tree;
	//tree.Insert(5);
	//tree.Insert(4);
	//tree.Insert(3);
	//tree.Insert(2);
	//tree.Insert(9);
	//tree.Insert(1);

	//tree.Insert(32);
	//tree.Insert(21);
	//tree.Insert(25);
	//tree.Insert(162);
	//tree.Insert(162);
	//tree.Insert(162);
	//tree.Insert(162);
	//tree.iterativeDFS();


	////tree.infixOrder();
	//tree.prefixOrder();
	//

	/*TreeNode* root = createFormula(in);
	prefixFormulaOrder(root);
	cout << printToStr(root) << endl;

	cout << culcFormula(root) << endl;*/
	//
	//

	//MyMap<char, int> map;
	
}
