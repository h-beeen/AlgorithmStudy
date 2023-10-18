/**
 * Problem - 1225. 암호생성기
 * 정답률 - 79.13
 * 난이도 - D3
 */

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int tc, divMin, tmp, fr, flag;
deque<int> code;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    for (int tcs = 1; tcs <= 10; tcs++) {

        while(!code.empty())
            code.pop_back();
        flag = 0;

        cin >> tc;
        divMin = 2147483647;
        for (int i = 0; i < 8; i++) {
            cin >> tmp;
            code.push_back(tmp);
//            if (divMin > (tmp / 15))
//                divMin = tmp / 15;
        }

//        for (int i = 0; i < 8; i++) {
//            code[i] -= (15 * divMin);
//        }

        while (1) {
            for (int i = 1; i <= 5; i++) {
                fr = code.front();
                code.pop_front();

                int now = fr - i;
                if (now <= 0) {
                    code.push_back(0);
                    flag = 1;
                    break;
                }
                code.push_back(now);
            }
            if (flag)
                break;
        }
        cout << '#' << tc << ' ';
        for (int i = 0; i < 8; i++)
            cout << code[i] << ' ';
        cout << '\n';
    }


}