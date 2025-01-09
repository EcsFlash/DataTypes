#pragma once
#include <fstream>
#include <iostream> 
#include <string> 
using namespace std;

template <typename T>
class FormulaTree {
public:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T _data) : data(_data), left(nullptr), right(nullptr) {}
    };

    Node* createFormula(const string& str) {
        StackList<Node*> operands;
        StackList<char> operators;


inline TTree createFormula(ifstream& fin) {
    char ch = fin.get();
    TTree node = new TreeNode;
    if (ch >= '0' && ch <= '9') {
        node->data = ch;
        node->left = nullptr;
        node->right = nullptr;
    }
    else if (ch == '(') {
        node->left = createFormula(fin);
        node->data = fin.get(); 
        node->right = createFormula(fin);
        ch = fin.get(); 
    }
    return node;
}


inline string printToStr(TTree root) {
    
        if (!root->left && !root->right) {
            return string(1, root->data);
        }
        else {
            return '(' + printToStr(root->left) + root->data + printToStr(root->right) + ')';
        }
 }


inline int culcFormula(TTree root) {
    if (!root->left && !root->right) {
        return root->data - '0';
    }
    else {
        int leftValue = culcFormula(root->left);
        int rightValue = culcFormula(root->right);
        switch (root->data) {
        case '-': return leftValue - rightValue;
        case '+': return leftValue + rightValue;
        case '*': return leftValue * rightValue;
        default:
            throw invalid_argument("Unknown operator");
        }
    }
private:
    Node* parseNumber(const string& str, int& i) {
        int start = i;
        while (i < str.length() && isdigit(str[i])) {
            i++;
        }
        int number = stoi(str.substr(start, i - start));
        return new Node(number);
    }


inline void prefixFormulaOrder(TreeNode* root) {
    if (root) {
        cout << root->data << endl;
        prefixFormulaOrder(root->left);
        prefixFormulaOrder(root->right);
    }
}

inline void deleteTree(TTree root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

    void processOperator(StackList<char>& operators, StackList<Node*>& operands) {
        char op = operators.peek();
        operators.remove();
        Node* right = operands.peek();
        operands.remove();
        Node* left = operands.peek();
        operands.remove();
        Node* node = new Node(op);
        node->left = left;
        node->right = right;
        operands.add(node);
    }

};