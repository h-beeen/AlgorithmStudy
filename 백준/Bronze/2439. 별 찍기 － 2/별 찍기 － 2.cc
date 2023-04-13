#include <iostream>
using namespace std;

int a, i, j;

int main() {

    cin >> a;
    for (j = 1; j <= a; j++) {
        for (int k = a - 1; k > i; k--) {
            cout << ' ';
        }
        for (i = 0; i < j; i++) {
            cout << '*';
        }
        cout << '\n';
    }

}