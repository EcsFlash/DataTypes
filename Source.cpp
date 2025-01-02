#include "LList.h"
#include "LListWH.h"
#include "DLList.h"
struct I {
	int i;
};

I sp[6];
int main() {
	LList<int> list;
	list.addToHead(1);
	list.addToHead(2);
	list.addToHead(3);
	list.addToHead(4);
	list.addToHead(5);
	list.addToHead(6);
	cout << list.sum();

}