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
	string to_hash;
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
	struct Iterator
	{
		Iterator(Node* ptr) : t_ptr(ptr), m_ptr(ptr) {}

		Node* operator*() const { return m_ptr; }
		//pointer operator->() { return m_ptr; }
		Iterator& operator++(int) {
			cout << "forward!!!" << endl;

			if (m_ptr && m_ptr->next) {
				m_ptr = m_ptr->next;
			}
			else{
				t_ptr++;
				while(!t_ptr) {
					t_ptr++;
					//m_ptr = t_ptr;
				}
			}
			return *this; 
		}
		void print() {
			cout << "HGG" << '\t' << m_ptr << "\t" << t_ptr << endl;
		}
		friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
		friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };
	private:
		Node* t_ptr;
		Node* m_ptr;
	};

	
	
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
		to_hash = "";
	}
	MapLinear() {
		SIZE = 100;
		table = new Node*[SIZE];
		for (int i = 0; i < SIZE; i++) {
			table[i] = nullptr;
		}
		//cout << "nulling" << endl;
		amount = 0;
	}
	~MapLinear() {
		for (int i = 0; i < SIZE; i++) {
			clear(table[i]);
		}
		delete[] table;
	};
	bool operator==(MapLinear& other) {
		for (int i = 0; i < SIZE; i++) {
			if (table[i]) {
				Node* temp = table[i];
				while (temp) {
					if (!other.search(temp->key)) {
						return false;
					}
					temp = temp->next;
				}
			}
		}
		return true;
	}
	void insert(const K& key, const V& value) {
		if (typeid(key) == typeid(string)) {
			to_hash += key;
		}
		
		if (amount * 3 > SIZE * 2) {
			resize();
		}
		size_t h = hash<K>()(key);//key.hash();
		int _hash = h % SIZE;
		//cout << h << endl;
		addToHead(table[_hash], key, value);
		amount++;
	}
	V& operator[](K& key) {
		if (typeid(key) == typeid(string)) {
			to_hash += key;
		}
		if (amount * 3 > SIZE * 2) {
			resize();
		}
		int _hash = hash<K>()(key) % SIZE;
		/*for (int i = 0; i < SIZE; i++) {
			cout << table[i] << endl;
		}*/
		//cout << _hash << '\t' << table[_hash] << '\t' << key;
		if (table[_hash] == nullptr) {
			//cout << "new node" << endl;
			table[_hash] = new Node(key, V());
			return table[_hash]->data;
		}
		else {
			//cout << "started search" << endl;
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
		int _hash = hash<K>()(key) % SIZE;//key.hash() % SIZE;
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
	MapLinear& operator=(const MapLinear& other) {
		delete[] table;
		table = new Node * [other.SIZE];
		SIZE = other.SIZE;
		amount = 0;
		/*MapLinear<K, V> map;*/
		for (int i = 0; i < other.SIZE; i++) {
			table[i] = nullptr;
			if (other.table[i]) {
				this->insert(other.table[i]->key, other.table[i]->data);
			}
		}
		return *this;
	}
	string get_hash() {
		if (typeid(K) == typeid(string)) {
			return to_hash;
		}
		throw invalid_argument("hih");
	}

	void print() {
		for (int i = 0; i < SIZE; i++) {
			print(table[i]);
		}
	}
	friend ostream& operator<< (ostream& os, MapLinear& map) {
		for (int i = 0; i < map.SIZE; i++) {
			if (map.table[i]) {
				os << endl << map.table[i];
			}
		}
		return os;
	}
	friend ostream& operator<<(ostream& os, Node*& head) {
		
			if (head) {
				Node* temp = head;
				while (temp != nullptr) {

					os << temp->key << " : " << temp->data << endl;
					temp = temp->next;
				}
				//os << endl;
			}
			return os;
	}

	Iterator begin() { 
		cout << "begin" << endl;
		return Iterator(table[0]); }
	Iterator end() { return Iterator(table[SIZE-1]); }
private:

	void print(Node* head) {
		if (head) {
			Node* temp = head;
			while (temp != nullptr) {

				cout << temp->data << " ";
				temp = temp->next;
			}
			//cout << endl;
		}
	}
	
	void addToHead(Node*& head, const K& key, const V& elem) {
		Node* newEl = new Node(key, elem);
		newEl->next = head;
		head = newEl;
		//cout << head << endl;
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

