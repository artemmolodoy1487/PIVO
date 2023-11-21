#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<vector<bool>>matrix;
  int size; cin >> size;
  for (int i = 0; i < size; i++) {
    vector<bool>line;
    for (int j = 0; j < size; j++) {
      bool input; cin >> input;
      line.push_back(input);
    }
    matrix.push_back(line);
  }
  for (int i = 0; i < size; i++) { for (int j = 0; j < size; j++) { cout << matrix[i][j]; }cout << endl; }
  double counter = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (matrix[i][j] == 1) {
        int status = false;
        for (int k = 0; k < size; k++) { if (matrix[i][k] == 1 && matrix[j][k] == 1) { status = true; } }
        if (status == false) { counter++; }
      }
    }
  }
  counter = counter / 2;
  cout << counter;
  
}
