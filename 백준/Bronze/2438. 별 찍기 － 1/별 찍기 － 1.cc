#include <iostream>

using namespace std;

int n;

int main(void) {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = n - i - 1; j < n; j++) {
            cout << '*';
        }
        cout << '\n';
    }
}