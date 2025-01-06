#pragma once


template<typename T>
class HashTableWithList {

	struct Node {
		T data;
		Node* next;
		Node() {
			data = T();
			next = nullptr;
		}
		Node(T _data) {
			data = _data;
			next = nullptr;
		}
	};
	Node** table;
	int SIZE;
	int amount;

	void resize() {
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
	}
public:
	HashTableWithList(int size) {
		SIZE = size;
		table = new Node*[size];
		for (int i = 0; i < SIZE; i++) {
			table[i] = nullptr;
		}
		amount = 0;
	}
	~HashTableWithList() {
		for (int i = 0; i < SIZE; i++) {
			clear(table[i]);
		}
		delete[] table;
	};
	void insert(const T& elem) {
		if (amount * 3 > SIZE * 2) {
			cout << "resi" << endl;
			resize();
		}
		long long h = elem.hash();
		int hash = h % SIZE;
		addToHead(table[hash], elem);
		amount++;
		cout << amount << endl;
	}
	void remove(const T& elem) {
		int hash = elem.hash() % SIZE;
		if (!table[hash]) {
			return;
		}
		else {
			if (table[hash]->data == elem) {
				delete_from_head(table[hash]);
					amount--;
			}
			else {
				Node* p = search_pos(table[hash], elem);
					if (p->next != nullptr) {
						deleteAfterNode(p);
						amount--;
					}
					else {
						return false;
					}
			}
		}
	}
	bool search(const T& elem) {
		int hash = elem.hash() % SIZE;
		if (table[hash] == nullptr) {
			return false;
		}
		else {
			if (table[hash]->data == elem) {
				return true;
			}
			if (search_pos(table[hash], elem)->next != nullptr) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	Node* search_pos(Node* head, const T& elem) {
		Node* cur = head;
		while (cur->next != nullptr && cur->next.data != elem) {
			cur = cur->next;
		}
		return cur;
	}
	HashTableWithList(const HashTableWithList& other) = delete;
	HashTableWithList& operator=(const HashTableWithList& other) = delete;

	void print() {
		for (int i = 0; i < SIZE; i++) {
			print(table[i]);
		}
	}
private:

	void print(Node* head) {
		Node* temp = head;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void addToHead(Node*& head, const T& elem) {
		Node* newEl = new Node(elem);
		newEl->next = head;
		head = newEl;
	}
	void delete_from_head(Node*& head) {

	}
	void delete_after_node(Node* p) {
	}

};