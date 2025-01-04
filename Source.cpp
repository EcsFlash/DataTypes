#pragma once
#include "InfixToPostfix.cpp"
#include "Calculate_formula.cpp"
#include "LListWH.h"
int main() {
	
	//cout << Calculator_formula();
	LListWH<int> list(new int [5] {1,2,3,4,5},5,false);
	list.print();
}