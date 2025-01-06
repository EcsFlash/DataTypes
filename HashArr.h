
template<typename T>
class HashTable2 {
	enum Status {
		FREE, USED, DELETED
	};
	struct Cell {
		Status status = FREE;
		T object;
		Cell() {
			status = FREE;
			object = T();
		}
		void clear() {
			status = DELETED;
		}
		void set(const T& obj) {
			object = obj;
			status = USED;
		}

	};

	Cell* table;
	int size;
	int c;
	int amount;
	int d; //only for example

	void insertToTable(Cell*& table, const T& elem) {
		long long h = elem.hash() % size;
		if (table[h].status != USED) {
			table[h].set(elem);
		}
		else {
			int i = 0;
			int hash_i = hash(i, h);
			while (table[hash_i].status == USED) {
				i++;
				hash_i = hash(i, h);
			}
			table[hash_i].set(elem);
		}
	}

	void resize() {
		Cell* tmp = new Cell[size * 2];
		int _size = size;
		size *= 2;
		for (int i = 0; i < size; i++) {
			if (table[i].status == USED) {
				insertToTable(tmp, table[i].object);
			}
		}
		delete[] table;
		table = tmp;
	}
	int hash(int i, long long h) {
		return (h + i * c) % size;
	}
	int hash_power2(int i, long long) {
		return (h + i * c + i * i * d) % size;
	}
	int hash_power2_other(int i, long long) {
		return (h + (i*i*c*c)) % size;
	}

	
public:
	HashTable2(int _size, int _c) {
		if (_c == 0) {
			throw invalid_argument("c parameter must be not 0");
		}
		table = new Cell[_size];
		size = _size;
		c = _c;
		amount = 0;
	}
	
	~HashTable2() {
		delete[] table;
	}
	void insert(const T& elem) {
		if (amount * 3 > size * 2) {
			resize();
		}
		insertToTable(table, elem);
		amount++;
	}

	void remove(const T& elem) {
		int index = indexOf(elem);
		if (index != -1) {
			table[index].clear();
			amount--;
		}
	}

	int indexOf(const T& elem) {
		long long true_hash = elem.hash();
		long long hash = true_hash % size;
		int i = 0;
		int hash_i = hash;
		while (table[hash_i].status != FREE) {
			if (table[hash].status == USED) {
				if (table[hash].object == elem) {
					return hash_i;
				}
			}
			i++;
			hash_i = hash(i, hash_i);
		}
		return -1;
	}
	bool search(const T& elem) {
		if (indexOF(elem) != -1)
		{
			return true;
		}
		return false;
	};
	void print() {
		for (int i = 0; i < size; i++) {
			cout << table[i].object << endl;
		}
	}
};