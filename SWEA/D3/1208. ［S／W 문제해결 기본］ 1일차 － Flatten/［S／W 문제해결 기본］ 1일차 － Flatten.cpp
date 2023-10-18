/**
 * Problem - 1204. 최빈수 구하기
 * 정답률 - 53.10
 * 난이도 - D2
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dumpCnt, dump, mxValue, mnValue, st, en;
vector<int> box;


bool reserveOrder(int a, int b) {
    return a > b;
}

int main(int argc, char **argv) {


    for (int tcs = 1; tcs <= 10; tcs++) {

        // 초기화
        while (!box.empty())
            box.pop_back();

        cin >> dumpCnt;

        for (int i = 0; i < 100; i++) {
            cin >> dump;
            box.push_back(dump);
        }

        sort(box.begin(), box.end() - 1, reserveOrder);

        for (int i = 0; i < dumpCnt; i++) {
            mxValue = *max_element(box.begin(), box.end());
            mnValue = *min_element(box.begin(), box.end());

            st = 0;
            en = box.size() - 1;


            while (box[st] != mxValue)
                st++;

            while (box[en] != mnValue)
                en--;

            box[st]--;
            box[en]++;

            if (box[st] - box[en] < 2)
                break;
        }

        mxValue = *max_element(box.begin(), box.end());
        mnValue = *min_element(box.begin(), box.end());

        cout << '#' << tcs << ' ' << mxValue - mnValue << endl;
    }
    return 0;
}