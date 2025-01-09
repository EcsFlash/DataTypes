

#pragma once
using namespace std;

template <typename T>
class AVLTree {
protected:
	struct Node {
		T data;
		int height;
		Node* left;
		Node* right;
		Node(T _data) {
			data = _data;
			height = 1;
			left = nullptr;
			right = nullptr;
		}
	};
	Node* root;

	int Height(Node* node)
	{
		return node ? node->height : 0;
	}

	bool isEmpty()
	{
		return root == nullptr;
	}
	void commitHeight(Node* node)
	{
		if (!node)
		{
			return;
		}
		int left = Height(node->left);
		int right = Height(node->right);
		node->height = (left > right ? left : right) + 1;
	}

	int Bfactor(Node* node)
	{
		return  Height(node->right) - Height(node->left);
	}

	void RightRotation(Node*& p)
	{

		Node* q = p->left;
		p->left = q->right;
		q->right = p;
		commitHeight(p);
		commitHeight(q);
		p = q;
	}

	void LeftRotation(Node*& p)
	{
		Node* q = p->right;
		p->right = q->left;
		q->left = p;
		commitHeight(p);
		commitHeight(q);
		p = q;
	}

	void balance(Node*& p)
	{
		int bfactor = Bfactor(p);
		if (bfactor == 2)
		{
			if (Bfactor(p->right) < 0)
				RightRotation(p->right);
			LeftRotation(p);
		}

		if (bfactor == -2)
		{
			if (Bfactor(p->left) > 0)
				LeftRotation(p->left);
			RightRotation(p);
		}
		commitHeight(p);

	}

	void Insert(Node*& node, T elem) {
		if (node == nullptr) {
			node = new Node(elem);
		}
		else if (elem < node->data) {
			Insert(node->left, elem);
		}
		else {
			Insert(node->right, elem);
		}
		balance(node);

	}

	void clear(Node*& node)
	{
		if (node != nullptr)
		{
			clear(node->left);
			clear(node->right);
			delete node;
			node = nullptr;
		}
	}

	int getWidth(int height) const {
		if (height == 1) {
			return 1;
		}
		return 2 * getWidth(height - 1);
	}


	void postOrder(Node* node) {
		if (node) {

			postOrder(node->right);
			postOrder(node->left);
			cout << node->data << "  ";
		}
	}

	void prefixOrder(Node*& node) {
		if (node) {
			cout << node->data << endl;
			prefixOrder(node->left);
			prefixOrder(node->right);
		}
	}

	void infixOrder(Node* node) {
		if (node) {
			infixOrder(node->left);
			cout << node->data << " ";
			infixOrder(node->right);
		}
	}
	T succesor(Node*& node) {	
		if (node->right) {
			return succesor(node->right);
		}
		else {
			Node* temp = node;
			T result = node->data;
			node = node->left;
			delete temp;
			temp = nullptr;
			return result;
		}
	}
	void remove(Node*& node, T elem) {
		if (node) {
			if (node->left && node->right) {
				T succ = succesor(node->left);
				node->data = succ;
			}
			else if (node->left && !node->right) {
				Node* temp = node;
				node = node->left;
				delete temp;
				temp = nullptr;
			}
			else if (!node->left && node->right) {
				Node* temp = node;
				node = node->right;
				delete temp;
				temp = nullptr;
			}
			else if (!node->left && !node->right) {
				delete node;
				node = nullptr;
				return;
			}
			balance(node);
		}
	}
public:
	AVLTree() {
		root = nullptr;
	}
	~AVLTree() {
		clear();
	}
	void Insert(T elem) {
		Insert(root, elem);
	}
	bool isOnlyRoot() const {
		return root && !root->left && !root->right;
	}
	void clear() {
		return clear(root);
	}
	void postOrder() {
		postOrder(root);
	}
	void prefixOrder() {
		prefixOrder(root);
	}
	void infixOrder() {
		infixOrder(root);
	}
	void remove(T elem) {
		remove(root, elem);
	}
	void bfs() {
		if (!isEmpty()) {
			Queue<Node*> que;
			que.enque(root);
			while (!que.isEmpty()) {
				Node* cur = que.peek();
				que.deque();
				cout << cur->data << endl;
				if(cur->left)
					que.enque(cur->left);
				if(cur->right)
					que.enque(cur->right);
			}
		}
	}
	void iterativeDFS() {
		StackList<Node*> stack;
		Node* cur = root;
		stack.addElem(cur);
		while (!stack.isEmpty())
		{
			if (cur->left) {
				cur = cur->left;
				stack.addElem(cur);
			}
			else {
				cur = stack.peek();
				stack.removeElem();
				cout << cur->data << endl;
				if (cur->right) {
					cur = cur->right;
					stack.addElem(cur);
				}

			}

		}
	}
	void iterativeDFSPR() {
		StackList<Node*> stack;
		Node* cur = root;
		stack.addElem(cur);
		while (!stack.isEmpty())
		{
			cur = stack.peek();
			stack.removeElem();
			cout << cur->data << endl;
			
			if (cur->right) {
				stack.addElem(cur->right);
			}
			if (cur->left) {
				stack.addElem(cur->left);
			}

			
		}
	}

};
