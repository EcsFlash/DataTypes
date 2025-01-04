#pragma once
#include <string>
#include <iostream>
using namespace std;
class Item {
	int id;
	string name;
public:
	Item(int _id, string _name) {
		id = _id;
		name = _name;
	}
	long long hash() const {
		long long h = 0;
		for (int i = 0; i < name.length(); i++) {
			h += (int)name[i] * pow(23, i);
		}
		return h + id;
	}
};