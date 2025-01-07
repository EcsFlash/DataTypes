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
	Item() {
		id = 0;
		name = "";
	}
	Item(const Item& obj) {
		id = obj.id;
		name = obj.name;
	}
	Item& operator=(const Item& obj) {
		id = obj.id;
		name = obj.name;
		return *this;
	}
	long long hash() const {
		long long h = 0;
		for (int i = 0; i < (int)name.length(); i++) {
			h += (int)name[i] * pow(23, i);
		}
		return h + id;
	}
	friend ostream& operator<<(ostream& os, const Item& obj) {
		return os << obj.name << " " << obj.id;
	}
};