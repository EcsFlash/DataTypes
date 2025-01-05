
struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int data) {
		this->data = data;
		left = nullptr;
		right = nullptr;
	}
};

//void initTree