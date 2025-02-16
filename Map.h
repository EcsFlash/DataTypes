#pragma once
#include "HashList.h"

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

	/*void resize() {
		Node** tmp = new Node * [SIZE * 2];
		for (int i = 0; i < SIZE; i++) {
			tmp[i] = table[i];
		}
		for (int i = SIZE; i < SIZE * 2; i++) {
			tmp[i] = nullptr;
		}
		SIZE *= 2;
		delete[] table;
		table = tmp;
	}*/
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
					int hash = h % (SIZE * 2);
					addToHead(tmp[hash], temp->key, temp->data);
					temp = temp->next;
				}
			}
		}
		SIZE *= 2;
		delete[] table;
		table = tmp;
	}

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
		table = new Node*[SIZE];
		for (int i = 0; i < SIZE; i++) {
			table[i] = nullptr;
		}
		amount = 0;
	}
	~MapLinear() {
		for (int i = 0; i < SIZE; i++) {
			clear(table[i]);
		}
		delete[] table;
	};
	void insert(const K& key, const V& value) {
		if (amount * 3 > SIZE * 2) {
			resize();
		}
		size_t h = hash<K>()(key);//key.hash();
		int _hash = h % SIZE;
		//cout << h << endl;
		addToHead(table[_hash], key, value);
		amount++;
	}
	V& operator[](K&& key) {
		int _hash = hash<K>()(key) % SIZE;
		if (table[_hash] == nullptr) {
			cout << "new node" << endl;
			table[_hash] = new Node(key, V());
			return table[_hash]->data;
		}
		else {
			cout << "started search" << endl;
			Node* searched = search_pos(table[_hash], key);
			if (table[_hash]->key == key) {
				return table[_hash]->data;
			}
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
		int _hash = hash<K>()(key) % SIZE;//key.hash() % SIZE;
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
		int _hash = hash<K>(key) % SIZE;//key.hash() % SIZE;
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
	MapLinear& operator=(const MapLinear& other) = delete;

	void print() {
		for (int i = 0; i < SIZE; i++) {
			print(table[i]);
		}
	}
private:

	void print(Node* head) {
		if (head) {
			Node* temp = head;
			while (temp != nullptr) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}
	void addToHead(Node*& head, const K& key, const V& elem) {
		Node* newEl = new Node(key, elem);
		newEl->next = head;
		head = newEl;
		cout << head << endl;
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