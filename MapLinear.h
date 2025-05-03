#pragma once
#include <iostream>
#include "math.h"
using namespace std;
template<typename K, typename V>
class MapLinear {
	struct Node {
		K key;
		V data;
		Node* next;
		Node() {
			key = K();
			data = V();
			next = nullptr;
		}
		Node(const K& _key, const V& _data) {
			key = _key;
			data = _data;
			next = nullptr;
		}
	};
	Node** table;
	int SIZE;
	int amount;
public:
	MapLinear(int size) {
		SIZE = size;
		table = new Node * [size];
		for (int i = 0; i < SIZE; i++) {
			table[i] = nullptr;
		}
		amount = 0;
	}
	MapLinear() {
		SIZE = 100;
		table = new Node * [SIZE];
		for (int i = 0; i < SIZE; i++) {
			table[i] = nullptr;
		}
		amount = 0;
	}
	~MapLinear() {
		for (int i = 0; i < SIZE; i++) {
			if (table[i]) {
				clear(table[i]);
			}
			else {
				delete table[i];
			}
		}
		delete[] table;
		table = nullptr;
	};
	void insert(const K& key, const V& value) {
		if (amount * 3 > SIZE * 2) {
			resize();
		}
		long long h = hash<K>()(key);
		int _hash = abs(h % SIZE);
		addToHead(table[_hash], key, value);
		amount++;
	}
	V& operator[](const K& key) {
		if (amount * 3 > SIZE * 2) {
			resize();
		}
		amount++;
		long long h = hash<K>()(key);
		int _hash = abs(h % SIZE);

		if (table[_hash] == nullptr) {
			table[_hash] = new Node(key, V());
			return table[_hash]->data;
		}
		else {
			if (table[_hash]->key == key) {
				return table[_hash]->data;
			}
			Node* searched = search_pos(table[_hash], key);

			if (searched->next != nullptr) {
				return searched->next->data;
			}
			else {
				addToHead(table[_hash], key, V());
				return table[_hash]->data;
			}
		}
	}
	bool remove(const K& key) {
		long long h = hash<K>()(key);
		int _hash = abs(h % SIZE);
		if (!table[_hash]) {
			return false;
		}
		else {
			if (table[_hash]->key == key) {
				deleteFromHead(table[_hash]);
				amount--;
				return true;
			}
			else {
				Node* p = search_pos(table[_hash], key);
				if (p->next != nullptr) {
					deleteAfter(p);
					amount--;
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
	bool search(const K& key) {
		int _hash = hash<K>()(key) % SIZE;
		if (table[_hash] == nullptr) {
			return false;
		}
		else {
			if (table[_hash]->key == key) {
				return true;
			}
			if (search_pos(table[_hash], key)->next != nullptr) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	Node* search_pos(Node* head, const K& key) {
		Node* cur = head;
		while (cur->next != nullptr && cur->next->key != key) {
			cur = cur->next;
		}
		return cur;
	}
	MapLinear(const MapLinear& other) = delete;
	void print() {
		for (int i = 0; i < SIZE; i++) {
			print(table[i]);
		}
	}
	int size() {
		return SIZE;
	}
private:
	void resize() {
		Node** tmp = new Node * [SIZE * 2];
		for (int i = 0; i < SIZE * 2; i++) {
			tmp[i] = nullptr;
		}
		for (int i = 0; i < SIZE; i++) {
			if (table[i]) {
				Node* temp = table[i];
				while (temp) {
					long long h = hash<K>()(temp->key);//temp->key.hash();
					int hash = abs(h % (SIZE * 2));
					addToHead(tmp[hash], temp->key, temp->data);
					temp = temp->next;
				}
			}
		}
		for (int i = 0; i < SIZE / 2; i++) {
			if (table[i]) {
				clear(table[i]);
			}
		}
		SIZE *= 2;

		delete[] table;
		table = tmp;
	}
	void print(Node* head) {
		if (head) {
			Node* temp = head;
			while (temp != nullptr) {

				cout << temp->key << " ";
				temp = temp->next;
			}
		}
	}
	void addToHead(Node*& head, const K& key, const V& elem) {
		Node* newEl = new Node(key, elem);
		newEl->next = head;
		head = newEl;
	}
	void deleteFromHead(Node*& head) {
		if (head) {
			Node* temp = head;
			head = head->next;
			delete temp;
			temp = nullptr;
		}
	}
	void deleteAfter(Node* p) {
		if (p) {
			Node* temp = p->next;
			p->next = temp->next;
			delete temp;
			temp = nullptr;
		}
	}
	void clear(Node*& node) {
		while (node) {
			deleteFromHead(node);
		}
	}
};
