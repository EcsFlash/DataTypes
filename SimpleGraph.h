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
		/*for (auto& i : wasIn) {
			cout << i << "  ";
		}
		cout << endl;*/
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
	int naiveTSP(int start) {
		start -= std_offset;
		int sum = INT_MAX;
		set<int> wasIn{ start };
		for (int i = 0; i < kernel.size(); i++) {
			if (kernel[start][i] != 0) {
				int temp = ntsp(i, wasIn, start) + kernel[start][i];
				if (temp < sum) {
					sum = temp;
				}
			}
		}
		return sum;
	}
	int ntsp(int start, set<int> wasIn, int realStart) {
		if ( kernel.size() - wasIn.size() == 1) {
			return kernel[start][realStart];
		}
		wasIn.insert(start);
		int sum = INT_MAX;
		for (int i = 0; i < kernel.size(); i++) {
			if (wasIn.count(i) == 0 && kernel[start][i] != 0) {
				int temp = ntsp(i, wasIn, realStart) + kernel[start][i];
				if (temp < sum) {
					sum = temp;
				}
			}
		}
		return sum;
	}

	int tspJ(int start) {
		start -= std_offset;
		set<int> wasIn{ start };
		int curr_indx = 0;
		int sum = 0;
		while(wasIn.size() < kernel.size()){
			int local_min = INT_MAX;
			int local_min_indx = -1;
			for (int j = 0; j < kernel.size(); j++) {
				if (kernel[curr_indx][j] < local_min && wasIn.count(j) == 0 && curr_indx != j) {
					local_min = kernel[curr_indx][j];
					local_min_indx = j;
				}
			}
			sum += local_min;
			wasIn.insert(local_min_indx);
			/*cout << "c_idx " << curr_indx <<  " idx " << local_min_indx << " : ";
			for (int i : wasIn) {
				cout << i << " ";
			}
			cout << endl;*/
			curr_indx = local_min_indx;
		}
		sum += kernel[curr_indx][0];
		return sum;
	}
};