#include <vector>
using namespace std;

class DSPathComp {
    struct Node {
        int name;
        Node* parent;
    };

    vector<Node*> verter;

public:
    DSPathComp(int size) {
        verter =  vector<Node*>(size, nullptr);
    }

    void makeset(int name) {
        verter[name] = new Node{ name, nullptr };
        verter[name]->parent = verter[name];
    }

    int find(int name) {
       /* Node* node = verter[name];
        while (node->parent != node) {
            node = node->parent;
        }
        return node->name;*/
        if (verter[name]->parent != verter[name]) {
            verter[name]->parent = verter[find(verter[name]->parent->name)];
        }
        return verter[name]->parent->name;
    }
    Node*& findE(Node*& el) {
        if (el->parent != el) {
            return findE(el->parent);
        }
        return el;
    }


    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            verter[rootY]->parent = verter[rootX];
        }
    }
};


class DSQuickFind {

    struct Node {
        int name;
        Node* next;
    };

    struct Root {
        int name;
        Node* first;
        Node* last;
        int len;
    };
   
    vector<Root> verter;
    vector<int> parents;

public:
    DSQuickFind(int n) {
        verter = vector<Root>(n);
        parents = vector<int>(n);
    }
    void makeset(int x) {
        Node* child = new Node{ x, nullptr };
        verter[x] = Root{ x, child, child, 1 };
        parents[x] = x;
    }
    int find(int x) {
        return parents[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (verter[rootX].len < verter[rootY].len) {
                verter[rootY].last->next = verter[rootX].first;
                Node* iter = verter[rootX].first;
                verter[rootY].last = verter[rootX].last;

                verter[rootX].first = nullptr;
                verter[rootX].last = nullptr;
                verter[rootX].len = 0;


                while (iter != nullptr) {
                    parents[iter->name] = rootY;
                    iter = iter->next;
                    verter[iter->name].first = nullptr;
                    verter[iter->name].last = nullptr; 
                    verter[iter->name].len = 0;
                }
                
            }
            else {
                verter[rootX].last->next = verter[rootY].first;
                Node* iter = verter[rootY].first;
                verter[rootX].last = verter[rootY].last;

                verter[rootY].first = nullptr;
                verter[rootY].last = nullptr;
                verter[rootY].len = 0;


                while (iter != nullptr) {
                    parents[iter->name] = rootX;
                    
                    verter[iter->name].first = nullptr;
                    verter[iter->name].last = nullptr;
                    verter[iter->name].len = 0;
                    iter = iter->next;
                }
            }
        }
    }
};