#include<iostream>

using namespace std;

int input;

int main(int argc, char **argv) {
    int test_case;
    int T;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> input;
        if (input % 2 == 0)
            cout << '#' << test_case << " Alice" << '\n';
        else
            cout << '#' << test_case << " Bob" << '\n';
    }
    return 0;
}