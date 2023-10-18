/**
 * Problem - 1926. 간단한 369게임
 * 정답률 - 32.37
 * 난이도 - D2
 */

#include <iostream>

using namespace std;

int cnt;
int clap;
string itoa;

int main(int argc, char **argv) {
    cin >> cnt;

    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= cnt; i++) {
        clap = 0;
        itoa = to_string(i);

        for (int j = 0; j < itoa.size(); j++) {
            if (itoa[j] == '3' || itoa[j] == '6' || itoa[j] == '9') {
                clap++;
            }
        }

        if (!clap)
            cout << itoa;

        while (clap){
            cout << '-';
            clap--;
        }
        cout << ' ';
    }

    return 0;
}