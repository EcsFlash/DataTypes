#include "LList.h"
//#include "LListWH.h"
#include "DLList.h"
struct I {
	int i;
};

I sp[6];
int main() {
	int a[5] = { 1,2,3,4,5 };
	DLList<int> list(a,5,true);
	//list.addAfter(nullptr, 5);
	list.print();

}