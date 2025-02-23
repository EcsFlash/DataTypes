#pragma once



template<typename K, typename V>
class Map {
	enum Status {
		FREE, USED, DELETED
	};
	struct Cell {
		Status status = FREE;
		K key;
		V object;
		Cell() {
			status = FREE;
			object = V();
		}
		void clear() {
			status = DELETED;
		}
		void set( const K& _key, const V& obj) {
			key = _key;
			object = obj;
			status = USED;
		}

	};

	Cell* table;
	int size;
	int c;
	int amount;
	int d; //only for example

	void insertToTable(Cell*& table, const K& key, V& velue) {
		long long h = hash<K>()(key) % size;
		if (table[h].status != USED) {
			table[h].set(key, velue);
		}
		else {
			int i = 0;
			int hash_i = _hash(i, h);
			while (table[hash_i].status == USED) {
				i++;
				hash_i = _hash(i, h);
			}
			table[hash_i].set(key, velue);
		}
	}

	void resize() {
		Cell* tmp = new Cell[size * 2];
		int _size = size;
		size *= 2;
		for (int i = 0; i < _size; i++) {
			if (table[i].status == USED) {
				insertToTable(tmp, table[i].key, table[i].object);
			}
		}
		delete[] table;
		table = tmp;
	}
	int _hash(int i, long long h) {
		return (h + i * c) % size;
	}
	int _hash_power2(int i, long long h) {
		return (h + i * c + i * i * d) % size;
	}
	int _hash_power2_other(int i, long long h) {
		return (h + (i * i * c * c)) % size;
	}


public:
	Map(int _size, int _c) {
		if (_c == 0) {
			throw invalid_argument("c parameter must be not 0");
		}
		table = new Cell[_size];
		size = _size;
		c = _c;
		amount = 0;
	}
	Map() {
		c = 1;
		size = 11;
		table = new Cell[size];
		amount = 0;
	}

	~Map() {
		delete[] table;
	}
	void insert(const K& key, const V& elem) {
		if (amount * 3 > size * 2) {
			resize();
		}
		insertToTable(table, key, elem);
		amount++;
	}
	/*V& operator[](K& key) {
		long long h = hash<K>()(key) % size;
		if (table[h].status != USED) {
			table[h].object;
		}
		else {
			int i = 0;
			int hash_i = _hash(i, h);
			while (table[hash_i].status == USED) {
				i++;
				hash_i = _hash(i, h);
			}
			table[hash_i].set(key, velue);
		}
	}*/
	void remove(const K& key) {
		int index = indexOf(key);
		if (index != -1) {
			table[index].clear();
			amount--;
		}
	}

	int indexOf(const K& key) {
		long long true_hash = hash<K>()(key);
		long long hash = true_hash % size;
		int i = 0;
		int hash_i = hash;
		while (table[hash_i].status != FREE) {
			if (table[hash_i].status == USED) {
				if (table[hash_i].key == key) {
					return hash_i;
				}
			}
			i++;
			hash_i = hash(i, hash_i);
		}
		return -1;
	}
	bool search(const K& key) {
		if (indexOF(key) != -1)
		{
			return true;
		}
		return false;
	};
	void print() {
		cout << '{' << endl;
		for (int i = 0; i < size; i++) {
			cout << table[i].key << ' ' << table[i].object << endl;
		}
		cout << '}' << endl;
	}
};


template<typename K, typename V>
class MyMap {
	
	struct Cell {
		K key;
		V object;
		Cell() {
			key = K();
			object = V();
		}
		void set(const K& _key, const V& obj) {
			key = _key;
			object = obj;
		}

	};

	Cell** table;
	int size;
	int c;
	int amount;
	int d; //only for example

	/*void insertToTable(Cell*& table, const K& key, V& velue) {
		long long h = hash<K>()(key) % size;
		if (table[h].status != USED) {
			table[h].set(key, velue);
		}
		else {
			int i = 0;
			int hash_i = _hash(i, h);
			while (table[hash_i].status == USED) {
				i++;
				hash_i = _hash(i, h);
			}
			table[hash_i].set(key, velue);
		}
	}

	void resize() {
		Cell* tmp = new Cell[size * 2];
		int _size = size;
		size *= 2;
		for (int i = 0; i < _size; i++) {
			if (table[i].status == USED) {
				insertToTable(tmp, table[i].key, table[i].object);
			}
		}
		delete[] table;
		table = tmp;
	}
	int _hash(int i, long long h) {
		return (h + i * c) % size;
	}
	int _hash_power2(int i, long long h) {
		return (h + i * c + i * i * d) % size;
	}
	int _hash_power2_other(int i, long long h) {
		return (h + (i * i * c * c)) % size;
	}*/


public:
	MyMap(int _size, int _c) {
		if (_c == 0) {
			throw invalid_argument("c parameter must be not 0");
		}
		table = new Cell[_size];
		size = _size;
		c = _c;
		amount = 0;
	}
	MyMap() {
		c = 1;
		size = 11;
		table = new Cell*[size];
		amount = 0;
		for (int i = 0; i < size; i++) {
			table[i] = nullptr;
			cout << table[i] << endl;
		}
	}

	~MyMap() {
		delete[] table;
	}
	/*void insert(const K& key, const V& elem) {
		if (amount * 3 > size * 2) {
			resize();
		}
		insertToTable(table, key, elem);
		amount++;
	}*/
	V& operator[](K& key) {
		long long h = hash<K>()(key) % size;
		if (table[h]) {
			table[h] = new Cell();
			*table[h].key = key;
			return *table[h].obj;
		}
		else {
			int i = 0;
			int hash_i = _hash(i, h);
			while (table[hash_i].status == USED) {
				i++;
				hash_i = _hash(i, h);
			}
			table[hash_i].set(key, velue);
		}
	}
	/*void remove(const K& key) {
		int index = indexOf(key);
		if (index != -1) {
			table[index].clear();
			amount--;
		}
	}

	int indexOf(const K& key) {
		long long true_hash = hash<K>()(key);
		long long hash = true_hash % size;
		int i = 0;
		int hash_i = hash;
		while (table[hash_i].status != FREE) {
			if (table[hash_i].status == USED) {
				if (table[hash_i].key == key) {
					return hash_i;
				}
			}
			i++;
			hash_i = hash(i, hash_i);
		}
		return -1;
	}
	bool search(const K& key) {
		if (indexOF(key) != -1)
		{
			return true;
		}
		return false;
	};
	void print() {
		cout << '{' << endl;
		for (int i = 0; i < size; i++) {
			cout << table[i].key << ' ' << table[i].object << endl;
		}
		cout << '}' << endl;
	}*/
};