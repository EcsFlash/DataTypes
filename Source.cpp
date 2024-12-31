#include "LList.h"
struct I {
	int i;
};

I sp[6];
int main() {
	LList<int> list;
	list.addToHead(2);
	list.addToHead(2);
	list.addToHead(2);
	list.extendSorted(new int[6] { 2, 6, 3, 8, 9, 1 }, 6);
	cout << list << endl;

}