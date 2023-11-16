#include <iostream> 
#include <algorithm> 
#include <vector>
using namespace std;
bool check(vector<vector<int>>v) {
	bool status = true;
	for (int i = 1; i < v.size(); i++) {
		for (int j = 0; j < v[i - 1].size(); j++) {
			for (int k = 0; k < v[i].size(); k++) {
				if (v[i - 1][j] == v[i][k]) { if (v[i - 1][j] != -1) { status = false; } }
			}
		}
	}
	return status;
}
int countingComps(vector<vector<int>>edges,vector<int>nodes) {
	int Componenta = 0;
	vector<int>unfoldedList_edges;
	for (int i = 0; i < edges.size(); i++) {
		for (int j = 0; j < edges[i].size(); j++) { unfoldedList_edges.push_back(edges[i][j]); }
	}
	for (int i = 0; i < nodes.size(); i++) {
		if (find(unfoldedList_edges.begin(), unfoldedList_edges.end(), nodes[i]) == unfoldedList_edges.end()) {
			Componenta++;
		}
	}
	while (check(edges) == false) {
		for (int i = 1; i < edges.size(); i++) {
			bool statusofInter = false;
			for (int j = 0; j < edges[i - 1].size(); j++) {
				for (int k = 0; k < edges[i].size(); k++) {
					if (edges[i - 1][j] == edges[i][k] && edges[i - 1][j] != -1) {
						statusofInter = true;
					}
				}
			}
			if (statusofInter == true) {
				for (int j = 0; j < edges[i].size(); j++) {
					edges[i - 1].push_back(edges[i][j]);
				}
				edges[i].clear(); // Очищаем объединенные вершины
			}
		}
		edges.erase(remove(edges.begin(), edges.end(), vector<int>()), edges.end()); // Удаляем пустые элементы
	}

	for (int i = 0; i < edges.size(); i++) {
		if (edges[i][0] != -1) { Componenta++; }
	}

	return Componenta;
}
int main() {
	setlocale(LC_ALL, "ru");
	vector<int>nodes;
	vector<vector<int>>edges;
	cout << "Какой порядок вашего неориентированного графа?" << endl;
	int order; cin >> order;
	for (int i = 0; i < order; i++) { nodes.push_back(i); }
	cout << "Сколько ребер в вашем графе" << endl;
	int number_of_edges; cin >> number_of_edges;
	cout << "Введите все ребра вашего графа" << endl << "Формат ввода:" << endl << "ребро 1 Enter ребро 2" << endl;
	for (int i = 0; i < number_of_edges; i++) {
		vector<int>edge;
		int n1, n2;
		cin >> n1;
		cin >> n2;
		edge.push_back(n1); edge.push_back(n2);
		edges.push_back(edge);
	}
	int bridges = 0;
	for (int i = 0; i < edges.size(); i++) {
		vector<vector<int>>edgeTRY;
		for (int j = 0; j < edges.size(); j++) {
			if (j != i) { edgeTRY.push_back(edges[j]); }
		}
		if (countingComps(edges, nodes) < countingComps(edgeTRY, nodes)) {
			bridges++;
		}
	}
	cout << "Количество мостов графа - " << bridges << endl;
	




}