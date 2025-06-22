#pragma once
#include <string>
#include <stdexcept>
using namespace std;



class PArrQueue {
	
	struct Elem {
		int priority;
		string value;
	};
	Elem* ptr;
	Elem** arr;
	int cap;
	int len;
public:
	PArrQueue(int n) {
		cap = n;
		arr = new Elem*[cap];
		for (int i = 0; i < cap; i++) {
			arr[i] = nullptr;
		}
		len = 0;
		ptr = *arr;
	}

	void Push(int p, string v) {
		Elem* e = new Elem{ p,v };
		if (!isEmpty()) {
			cout << arr[0]->value << endl;
		}
		
		if (len >= cap) {
			throw "no mama";
		}
		
		else {
			int i = 0;
			while(arr[i])
			{
				if (arr[i] && arr[i]->priority < e->priority) {
					for (int j = len; j > i; j--) {
						swap(arr[j], arr[j - 1]);
					}
					arr[i] = e;
					len++;
					return;
				}
				i++;
			}
			arr[i] = e;
			len++;
			return;
		}
		
	}

	string Pop() {
		if (!arr[0]) {
			throw "no data";
		}
		string result = (*arr[0]).value;
		arr[0] = nullptr;
		for (int i = 0; i < len; i++) {
			swap(arr[i], arr[i + 1]);
		}
		return result;
	}

	bool isEmpty() {
		return arr[0] == nullptr;
	}

	void clear() {
		for (int i = 0; i < cap; i++) {
			arr[i] = nullptr;
		}
		len = 0;
	}
};