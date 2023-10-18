/**
 * Problem - 1204. 최빈수 구하기
 * 정답률 - 53.10
 * 난이도 - D2
 */

#include <iostream>
#include <cstring>

using namespace std;

int T;
int cnt;
int tcs;
int temp;
int mxKey;
int mxValue;
int value[1005];

int main(int argc, char **argv) {

//    freopen("input.txt", "r", stdin);
    cin >> T;
    for (int test_case = 0; test_case < T; test_case++) {

        //초기화
        mxKey = 0;
        mxValue = 0;
        std::memset(value, 0, sizeof(value));

        cin >> tcs;

        for (int i = 0; i < 1000; i++) {
            cin >> temp;
            value[temp]++;
        }


        for (int i = 1; i <= 100; i++) {
            if (value[i] >= mxValue) {
                mxKey = i;
                mxValue = value[i];
            }
        }

        cout << "#" << tcs << ' ' << mxKey << '\n';
    }

    return 0;
}