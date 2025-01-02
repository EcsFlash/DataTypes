#include "LList.h"
#include "LListWH.h"
#include "DLList.h"
#include "StackList.h"
#include "StackArr.h"

bool BracketBalance();

int main() {
	
	StackArr<int> stack(5);
	stack.addElem(1);
	stack.addElem(2);
	stack.addElem(3);
	stack.addElem(4);
	stack.addElem(5);
	stack.addElem(6);
	stack.addElem(7);
	stack.addElem(8);
	stack.addElem(9);
	stack.addElem(10);
	stack.removeElem();
	stack.removeElem();
	stack.removeElem();
	stack.removeElem();
	stack.removeElem();
	cout << stack.peek();
	//stack.clear();
	//cout << stack.isEmpty();
	//cout << stack.peek();
	//stack.print();
	//stack.print();
}