#pragma once
#include "InfixToPostfix.cpp"
#include "Calculate_formula.cpp"
#include "HashArr.h"
#include "Item_for_hash.h"
int main() {
	HashTable2<Item> hashT(100, 0);
	//for (int i = 0; i < 70; i++) {
	//	hashT.insert(Item(i, "pukpuk"));
	//}
	//
	hashT.insert(Item(12, "pukpuk"));
	hashT.insert(Item(12, "pukpuk"));
	hashT.print();
	//cout << Calculator_formula();
}