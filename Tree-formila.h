#pragma once
#include <fstream>
#include <iostream> 
#include <string> 
using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
};

using TTree = TreeNode*;


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
}