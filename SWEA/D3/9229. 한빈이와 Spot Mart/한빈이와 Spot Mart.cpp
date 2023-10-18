/**
 * Problem - 1215. 회문1
 * 정답률 - 81.76
 * 난이도 - D3
 */

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int tc, snackCnt, snackWeight, snack[2000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tc;
    for (int tcs = 1; tcs <= tc; tcs++) {
        cin >> snackCnt >> snackWeight;

        for (int s = 0; s < snackCnt; s++)
            cin >> snack[s];

        sort(snack, snack + snackCnt);

        int st = 0;
        int en = snackCnt - 1;
        int maxWeight = 0;

        while (st < en) {
            // 최대 무게 초과일 경우
            if (snack[st] + snack[en] > snackWeight) en--;

            // 최대 무게 미만일 경우
            else if (snack[st] + snack[en] < snackWeight) {
                maxWeight = max(maxWeight, snack[st] + snack[en]);
                st++;
            }
            // 최대 무게를 드는 경우의 수를 찾았을 때
            else {
                maxWeight = snack[st] + snack[en];
                break;
            }
        }
        if (!maxWeight)
            maxWeight = -1;
        cout << '#' << tcs << ' ' << maxWeight << '\n';
    }
}