#pragma once
#include "queue"
#include "stack"
#include <iostream>
using namespace std;
template <typename T>
class PHQueue {
	struct node {
		T data;
		int PRIORA;
		node* left;
		node* right;
		node(T _data, int p) {
			data = _data;
			PRIORA = p;
			left = right = nullptr;
		}
		friend ostream& operator<<(ostream& os, node*& node) {
			os << '(' << node->data << ',' << node->PRIORA << ')';
			return os;
		}
	};
	node* root;
	int size;

	void balance(node*& node) {
		if (node) {
			if (node->left && node->left->PRIORA > node->PRIORA) {
				swap(node, node->left);
			}
			if (node->right && node->right->PRIORA > node->PRIORA) {
				swap(node, node->right);
			}
			balance(node->left);

			balance(node->right);

		}
	}
	node* balanceNewbie(node* n, node* newbie) {
		if (n) {
			if (n == newbie) {
				return n;
			}
			node* left = balanceNewbie(n->left, newbie);
			node* right = balanceNewbie(n->right, newbie);
			if (left) {
				if (left->PRIORA > n->PRIORA) {
					swap(left, n);
				}
			}
			else if (right) {
				if (right->PRIORA > n->PRIORA) {
					swap(right, n);
				}
			}

		}
		else {
			return nullptr;
		}
	}

	void swap(node*& node1, node*& node2) {
		T tempD = node1->data;
		int tempP = node1->PRIORA;
		node1->data = node2->data;
		node1->PRIORA = node2->PRIORA;
		node2->data = tempD;
		node2->PRIORA = tempP;
	}
public:
	PHQueue() {
		root = nullptr;
		size = 0;
	}
	void add(T data, int p) {
		if (root) {
			// создаем очередб для обхода в ширину
			queue<node*> q;
			//  добавляем корень в очередь
			q.push(root);
			// инициализируем огрызка(0 или 1 наследник)
			node* temp = root;
			// пока очередь не пуста продолжаем обход
			while (!q.empty()) {
				// достаем из очереди предполагаемого огрызка
				temp = q.front();
				// если есть оба наслдника - удаляем(если не огрызок),
				// таким образом огрызок останется в начале очереди
				if (temp->left && temp->right) {
					q.pop();
				}
				// как только обнаружили огрызка, прекращаем обход
				else {
					break;
				}
				// если все наследники на месте, продолжаем
				if (temp->left) {
					q.push(temp->left);
				}
				if (temp->right) {
					q.push(temp->right);
				}
			}
			if (temp->left) {
				temp->right = new node(data, p);
				balanceNewbie(root, temp->right);
			}
			else {
				temp->left = new node(data, p);
				balanceNewbie(root, temp->left);
			}
		}
		else {
			root = new node(data, p);
		}
	}
	T pop() {
		if (root) {
			queue<node*> q;
			stack<node*> s;
			T result = root->data;
			q.push(root);
			s.push(root);
			int _size = 0;
			node* temp = root;
			while (!q.empty()) {
				temp = q.front();
				if (temp->left && temp->right) {
					//докидываем в стэк полноценных рожителей
					s.push(temp);
					//удаляем их же из очереди
					q.pop();
				}
				// как только доходим 
				else {
					break;
				}

				if (temp->left) {
					q.push(temp->left);
				}
				if (temp->right) {
					q.push(temp->right);
				}
			}

			if (!temp->left && !temp->right) {
				if (temp == root) {
					root = nullptr;
					return result;
				}
				else {
					temp = s.top();
					root->data = temp->right->data;
					root->PRIORA = temp->right->PRIORA;
					temp->right = nullptr;
				}
			}
			else {
				if (temp->right) {
					root->data = temp->right->data;
					root->PRIORA = temp->right->PRIORA;
					temp->right = nullptr;
				}
				else if (temp->left) {
					root->data = temp->left->data;
					root->PRIORA = temp->left->PRIORA;
					temp->left = nullptr;
				}
			}
			balance(root);
			return result;
		}
	}
	T pop2() {
		if (root) {
			queue<node*> q;
			T result = root->data;
			q.push(root);
			int _size = 0;
			node* temp = root;
			node* parent = nullptr;
			while (!q.empty()) {
				temp = q.front();
				q.pop();
				if (temp->left) {
					parent = temp;
					q.push(temp->left);
				}
				if (temp->right) {
					parent = temp;
					q.push(temp->right);
				}
			}
			if (parent) {
				if (parent->left == temp) {
					parent->left = nullptr;
				}
				else if (parent->right == temp) {
					parent->right = nullptr;
				}
			}
			else {
				root = nullptr;
			}
			root->data = temp->data;
			root->PRIORA = temp->PRIORA;
			delete temp;
			balance(root);
			return result;
		}
	}
	void print() {
		if (root) {
			queue<node*> q;
			q.push(root);
			node* temp = root;
			while (!q.empty()) {
				temp = q.front();
				cout << temp << '\t';
				q.pop();
				if (temp->left) {
					q.push(temp->left);
				}if (temp->right) {
					q.push(temp->right);
				}
			}

		}
		cout << endl;
	}
	T peek() {
		if (root) {
			return root->data;
		}
		throw invalid_argument("error");
	}
	bool isEmpty() {
		return root == nullptr;
	}
};