
template<typename T>
class BinaryTree {
	struct Node {
		T data;
		Node* left;
		Node* right;
		Node(T data) {
			this->data = data;
			left = nullptr;
			right = nullptr;
		}
	};
	Node* root;
public:
	BinaryTree() {
		root = nullptr;
	}
	BinaryTree(T element) {
		root = new Node(element);
	}
	BinaryTree(T root, T left, T right) {
		this->root = new Node(root);
		root->left = new Node(left);
		root->right = new Node(right);
	}
	void attachLeft(T data) {
		Node* newElement = new Node(data);

	}
};