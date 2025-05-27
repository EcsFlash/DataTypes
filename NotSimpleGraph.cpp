#pragma once
#include "map"
#include <vector>
#include <iostream>
#include <set>
#include <queue>
using namespace std;

struct Edge {
	char name;
	double weight;
};

class NotSimpleGraph {
	
	map<char, vector<Edge>> listA;

	void dfsr(char start, set<char>& visited) {
		for (Edge& e : listA[start]) {
			if (visited.count(e.name) == 0) {
				visited.insert(e.name);
				dfsr(e.name, visited);
			}
		}
	}
public:
	

	void AddDirectedEdge(char from, char to, double weight) {
		listA[from].push_back(Edge{to,weight});
	}

	void AddEdge(char from, char to, double weight) {
		listA[from].push_back(Edge{ to,weight });
		listA[to].push_back(Edge{ from,weight });
	}

	void RemoveEdge(char from, char to) {
		vector<Edge>* curr_vect = &listA[from];
		for (int i = 0; i < (*curr_vect).size(); i++) {
			if ((*curr_vect)[i].name == to) {
				(*curr_vect).erase((*curr_vect).begin() + i);
			}
		}
		
	}
	void print() {
		for (auto& [k, v] : listA) {
			cout << int(k) << " : ";
			for (auto& i : v) {
				cout << "(" << int(i.name) << "," << i.weight << ")" << ' ';
			}
			cout << endl;
		}
	}

	set<char> DFSR(char start) {
		set<char> visited;
		visited.insert(start);
		dfsr(start, visited);
		return visited;
	}


	void BFS(char start) {
		queue<char> q;
		set<char> visited;
		q.push(start);
		while (!q.empty()) {
			char v = q.front();
			q.pop();
			visited.insert(v);
			for (Edge& e : listA[v]) {
				if (!visited.contains(e.name)) {
					q.push(e.name);
				}
			}
		}
		for (int v : visited) {
			cout << v << endl;
		}
	}


	double naiveTSP(char start) {
		double sum = INT_MAX;
		set<char> wasIn{ start };
		for (Edge& e: listA[start]) {
				int temp = ntsp(e.name, wasIn, start) + e.weight;
				if (temp < sum) {
					sum = temp;
				}
			
		}
		return sum;
	}
	double ntsp(char start, set<char> wasIn, char realStart) {
		if (listA.size() - wasIn.size() == 1) {
			for (Edge& e : listA[start]) {
				if (e.name == realStart) {
					return e.weight;
				}
			}
		}
		wasIn.insert(start);
		for (Edge& e : listA[start]) {
			if (!wasIn.contains(e.name)) {
				return ntsp(e.name, wasIn, realStart) + e.weight;
			}
		}
	}


	int TSPJ(char start) {
		set<char> visited{ start };
		char cur_vertex = start;
		double sum = 0;
		while (listA.size() > visited.size()) {
			double min = INT_MAX;
			char next_vertex = -1;
			cout << int(cur_vertex) << endl;
			for (Edge& e : listA[cur_vertex]) {
				if (!visited.contains(e.name) && e.weight < min && e.name != start) {
					min = e.weight;
					next_vertex = e.name;
				}
			}
			sum += min;
			cur_vertex = next_vertex;
			visited.insert(next_vertex);
		}
		for (Edge& e : listA[cur_vertex]) {
			if (e.name == start) {
				sum += e.weight;
			}
		}
		return sum;
	}


	/*vector<vector<int>> Warshall() {
		vector<vector<int>> result = vector<vector<int>>(listA.size(), vector<int>(listA.size(), 0));
		for()
	}*/
};


