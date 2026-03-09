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

    vector<int> a(m , 0);

    for (int j = 0; j < m; j++) {
        int used = 0;
        for (int i = 0; i < n; i++) {
            used += c[i][j];
        }
        a[j] = e[j] - used;
    }

    cout << "\navailable resources:\n";
    for (int i = 0; i < m; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    vector<int> work = a;
    vector<bool> finish(n , false);

    bool foundSomething = true;

    while (foundSomething) {
        foundSomething = false;

        for (int i = 0; i < n; i++) {
            if (finish[i]) {
                continue;
            }

            bool canRun = true;

            for (int j = 0; j < m; j++) {
                if (r[i][j] > work[j]) {
                    canRun = false;
                    break;
                }
            }

            if (canRun) {
                for (int j = 0; j < m; j++) {
                    work[j] += c[i][j];
                }

                finish[i] = true;
                foundSomething = true;
            }
        }
    }

    bool deadlock = false;

    for (int i = 0; i < n; i++) {
        if (!finish[i]) {
            deadlock = true;
            break;
        }
    }

    cout << "\nfinal result:\n";

    if (deadlock) {
        cout << "deadlock found\n";
        cout << "deadlocked processes: ";

        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                cout << "p" << i << " ";
            }
        }
        cout << endl;
    }
    else {
        cout << "no deadlock found\n";
    }

    return 0;
}