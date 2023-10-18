/**
 * Problem - 1264. View
 * 정답률 - 67.00
 * 난이도 - D3
 */

#include <iostream>
#include <cstring>

using namespace std;

int sz, value[2000], result;


int main(int argc, char **argv) {

//    freopen("input.txt", "r", stdin);

    for (int test_case = 1; test_case <= 10; test_case++) {

        //초기화
        result = 0;
        memset(value, 0, sizeof(value));
        cin >> sz;

        for (int i = 0; i < sz; i++)
            cin >> value[i];

        for (int i = 2; i <= sz-2; i++) {
            int beforeTowValue = value[i - 2];
            int beforeOneValue = value[i - 1];
            int afterOneValue = value[i + 1];
            int afterTwoValue = value[i + 2];

            int tempMax = max(max(beforeOneValue, beforeTowValue),
                              max(afterOneValue, afterTwoValue));

            if (value[i] > tempMax) {
                result += value[i] - tempMax;
                i += 2;
            }
        }
        cout << "#" << test_case << ' ' << result << '\n';
    }

    return 0;
}