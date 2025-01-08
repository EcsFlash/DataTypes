#pragma once

#include <string>
#include <iostream>
#include "StackList.h"

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

        int i = 0;
        while (i < str.length()) {
            char ch = str[i];
            if (isdigit(ch)) {
                operands.add(parseNumber(str, i));
            }
            else if (ch == '(') {
                operators.add(ch);
                i++;
            }
            // Закрывающая скобка
            else if (ch == ')') {
                while (!operators.isEmpty() && operators.peek() != '(') {
                    processOperator(operators, operands);
                }
                operators.remove();
                i++;
            }
            // Операторы
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                while (!operators.isEmpty() && precedence(operators.peek()) >= precedence(ch)) {
                    processOperator(operators, operands);
                }
                operators.add(ch);
                i++;
            }
        }

        while (!operators.isEmpty()) {
            processOperator(operators, operands);
        }

        return operands.peek();
    }

    void printInOrder(Node* node) {
        if (node) {
            if (node->left) printInOrder(node->left);

            if (node->data == '+' || node->data == '-' || node->data == '*' || node->data == '/') {
                cout << (char)node->data << " ";
            }
            else {
                cout << node->data << " ";
            }

            if (node->right) printInOrder(node->right);
        }
    }
    T evaluate(Node* root) {
        if (root == nullptr) {
            throw invalid_argument("Tree is empty");
        }
        if (!(root->data == '+' || root->data == '-' || root->data == '*' || root->data == '/')) {
            return root->data;
        }
        T leftValue = evaluate(root->left);
        T rightValue = evaluate(root->right);

        switch (root->data) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            if (rightValue == 0) {
                throw invalid_argument("Division by zero");
            }
            return leftValue / rightValue;
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

    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
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