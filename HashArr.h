
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
	};

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
	};
	int hash(int i, long long h) {
		return (h + i * c) % size;
	};
public:
	HashTable2(int _size, int _c) {
		if (c <= 0) {
			throw invalid_argument("c parameter must be greather than 0");
		}
		table = new Cell[_size];
		size = _size;
		c = _c;
		amount = 0;
	};
	HashTable2(const HashTable2& other) : size(other.size), c(other.c), amount(other.amount) {
		table = new Cell[size];
		for (int i = 0; i < size; ++i) {
			table[i] = other.table[i];
		}
	};
	HashTable2& operator=(const HashTable2& other) {
		if (this != &other) {
			delete[] table;
			size = other.size;
			c = other.c;
			amount = other.amount;
			table = new Cell[size];
			for (int i = 0; i < size; ++i) {
				table[i] = other.table[i];
			}
		}
		return *this;
	};
	~HashTable2() {
		delete[] table;
	};
	void insert(const T& elem) {
		if (amount * 3 > size * 2) {
			resize();
		}
		insertToTable(table, elem);
		amount++;
	};
	void remove(const T& elem) {
		int index = indexOf(elem);
		if (index != -1) {
			table[index].clear();
			amount--;
		}
	};
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
		throw runtime_error("element not found")
	};
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
	};
};