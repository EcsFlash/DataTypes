#pragma once

#include <iostream> 
#include <string> 
using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
};

using TTree = TreeNode*;


TTree createFormula(istream& fin) {
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


string printToStr(TTree root) {
    if (!root->left && !root->right) {
        return string(1, root->data);
    }
    else {
        return '(' + printToStr(root->left) + root->data + printToStr(root->right) + ')';
    }
}


int culcFormula(TTree root) {
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


void deleteTree(TTree root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}