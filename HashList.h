template<typename T>
class HashTableWithList {

	struct Node {
		T data;
		Node* next;
	};
	Node** table;
	int SIZE;
	int amount;
public:
	HashTableWithList(int size) {
		SIZE = size;
		table = new Node * [size];
		amount = 0;
	}
	~HashTableWithList() {
		for (int i = 0; i < SIZE; i++) {
			table[i].clear();
		}
		delete[] table;
	};
	void insert(const T& elem) {
		long long h = elem.hash();
		int hash = h % SIZE;
		addToHead(table[hash], elem);
	}
	void remove(const T& elem) {
		int hash = elem.hash() % SIZE;
		if (!table[hash]) {
			return;
		}
		else {
			if (table[hash]->data == elem) {
				delete_from_head(table[hash])
					amount--;
			}
			else {
				Node* p = search_pos(table[hash], elem)
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
private:
	void addToHead(Node*& head, const T& elem) {
	}
	void delete_from_head(Node*& head) {
	}
	void delete_after_node(Node* p) {
	}

};