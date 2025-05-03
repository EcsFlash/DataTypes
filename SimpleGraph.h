#pragma once
#include <vector>
#include <iostream>
#include <set>
#include <fstream>
#include <stack>
#include <queue>
using namespace std;


class SimpleGraph {
	vector<vector<int>> kernel;
	const unsigned int std_offset;

	void dfsRecursive(int start, set<int>& wasIn) {		
		for (int i = 0; i < kernel.size(); i++)
		{
			if (kernel[start][i] != 0)
			{
				if (wasIn.count(i) == 0)
				{
					wasIn.insert(i);
					wasIn.insert(start);
					//cout << i+std_offset << endl;
					dfsRecursive(i, wasIn);
				}
			}
		}
		
	}
	
public:
	SimpleGraph(vector<vector<int>>& m): std_offset(1) {
		for (int i = 0; i < m.size(); i++) {
			if(m[i].size() != m.size()) {
				throw invalid_argument("kernel must be size of n * n, n > 0");
			}
		}
		this->kernel = m;
	}
	set<int> DFSR(int start) {
		start -= std_offset;
		set<int> wasIn;
		dfsRecursive(start, wasIn);
		return wasIn;
	}
	set<int> DFSI(int entry_point) {
		int row = entry_point;
		set<int> wasIn = { entry_point };
		stack<int> rowsH;
		bool isOver = false;
		while (!isOver) {
			bool flag = false;
			for (int i = 0; i < kernel.size(); i++) {
				if (kernel[row][i] != 0 && wasIn.count(i) == 0) {
					wasIn.insert(i);
					rowsH.push(row);
					row = i;
					flag = true;
					break;
				}
			}
			if (!flag) {
				if (rowsH.empty()) {
					isOver = true;
				}
				else {
					row = rowsH.top();
					rowsH.pop();
				}
			}
		}
		return wasIn;
	}
	set<int> BFSI(int start) {
		start -= std_offset;
		queue<int> q;
		q.push(start);
		set<int> wasIn = { start };
		while (!q.empty())
		{
			int elem = q.front();
			q.pop();
			for (int i = 0; i < kernel.size(); i++) {
				if (kernel[elem][i] != 0 && wasIn.count(i) == 0) {
					q.push(i);
					wasIn.insert(i);
				}
			}
		}
		for (auto& i : wasIn) {
			cout << i << "  ";
		}
		cout << endl;
		return wasIn;
	}
	void print()
	{
		for (int i = 0; i < kernel.size(); i++)
		{
			for (int j = 0; j < kernel.size(); j++)
			{
				cout << kernel[i][j] << ' ';
			}
			cout << endl;
		}
	}

	int countPieces() {
		set<set<int>> pieces;
		for (int i = 0; i < kernel.size(); i++) {
			set<int> p;
			dfsRecursive(i, p);
			for (auto& i : p) {
				cout << i << "  ";
			}
			cout << endl;
			pieces.insert(p);
		}
		return pieces.size();
	}
};