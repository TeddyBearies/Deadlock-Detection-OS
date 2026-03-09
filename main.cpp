#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile("input.txt");

    int n , m;
    inputFile >> n >> m;

    vector<int> e(m);
    for (int i = 0; i < m; i++) {
        inputFile >> e[i];
    }

    vector<vector<int>> c(n , vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            inputFile >> c[i][j];
        }
    }

    vector<vector<int>> r(n , vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            inputFile >> r[i][j];
        }
    }

    inputFile.close();

    cout << "processes: " << n << endl;
    cout << "resource types: " << m << endl;

    cout << "\nexisting resources:\n";
    for (int i = 0; i < m; i++) {
        cout << e[i] << " ";
    }
    cout << endl;

    cout << "\nallocation matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nrequest matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}