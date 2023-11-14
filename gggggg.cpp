#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
bool check(vector<vector<int>>v) {
	bool status = true;
	for (int i = 1; i < v.size(); i++) {
		for (int j = 0; j < v[i - 1].size(); j++) {
			for (int k = 0; k < v[i].size(); k++) {
				if (v[i - 1][j] == v[i][k] && v[i - 1][j] != -1) { status = false; }
			}
		}
	}
	return status;
}
int findCOMP(vector<vector<int>>edges,int size) {
	while (check(edges) == false) {

		for (int i = 1; i < size; i++) {
			bool statusofInter = false;
			for (int j = 0; j < edges[i - 1].size(); j++) {
				for (int k = 0; k < edges[i].size(); k++) {
					if (edges[i - 1][j] == edges[i][k] && edges[i - 1][j] != -1) { statusofInter = true; }
				}
			}
			if (statusofInter == true) {
				for (int j = 0; j < edges[i].size(); j++) {
					edges[i - 1].push_back(edges[i][j]);
				}
			}
			for (int j = 0; j < edges[i].size(); j++) {
				edges[i][j] = -1;
			}


		}
	}
	int componenta = 0;
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i][0] != -1) { componenta++; }
	}
	return componenta;
}

int main() {
	vector<vector<int>>edges;
	int size;
	cin >> size;
	for (int i = 0; i < size; i++) {
		vector<int>edge;
		int f; cin >> f;
		int t; cin >> t;
		edge.push_back(f);
		edge.push_back(t);
		edges.push_back(edge);
	}
		int bridge = 0;
		for (int i = 0; i < edges.size(); i++) {
			vector<vector<int>>back;
			for (int j = 0; j < edges.size(); j++) {
				if (j != i) {
					back.push_back(edges[j]);
				}
			}
			if (findCOMP(edges, edges.size()) != findCOMP(back, back.size())) { bridge++; }
		}
		cout << bridge << endl;
	}





