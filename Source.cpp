#include "LList.h"
#include "LListWH.h"
#include "DLList.h"
struct I {
	int i;
};

I sp[6];
int main() {
	int a[5] = { 1,4,5,2,6 };
	LList<int> list(a,5);
	//list.addAfter(nullptr, 5);
	//list.clear();
	list.print();

}