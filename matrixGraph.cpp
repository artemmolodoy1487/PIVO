#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	cout<<"Введите количество узлов графа" << endl;
	int size;
	cin >> size;
	vector<vector<bool>>graph;
	for (int i = 0; i < size; i++) {
		vector<bool> row;
		for (int j = 0; j < size; j++) {
			row.push_back(false);
		}
		graph.push_back(row);
	}
	cout << "Вводите граф по стандарту:" << endl;
	cout << "<какой узел><с каким>,если вы введете f ввод будет окончен" << endl;
	while (true) {
		string str;
		cin >> str;
		if (str == "f") { break; }
		int a = str[0] - '0';
		int b = str[1] - '0';
		graph[a][b] = true;
		graph[b][a] = true;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	vector<bool>marker;
	marker.resize(size);
	int componenta = 1;
	graph[]

	

	
}