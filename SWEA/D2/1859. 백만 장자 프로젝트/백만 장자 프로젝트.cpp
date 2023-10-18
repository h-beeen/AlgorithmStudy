#include <iostream>
#include <cstring>

using namespace std;
    int T;
    int test_case = 0;
    int valueSize;
    int mxValue;
    long long temp ;
    long long result;
    int value[1000005];

int main(int argc, char **argv) {

    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++) {
            // 초기화 로직
            valueSize = 0;
            mxValue = 0;
            temp = 0;
            result = 0;
            std::memset(value, 0, sizeof(value));
        
        cin >> valueSize;

        for (int i = 0; i < valueSize; i++)
            cin >> value[i];

        mxValue = value[valueSize - 1];

        for (int i = valueSize - 2; i >= 0; i--) {

            // 현재 값이 mxValue보다 커서 갱신해야 할 때
            if (value[i] > mxValue) {
                result += temp;
                mxValue = value[i];
                temp = 0; // temp 초기화
            }

                // 현재 값이 mxValue보다 작아서 순회할 때 (같으면 처리 X)
            else if (value[i] < mxValue) {
                temp += mxValue - value[i];
            }
        }

        result += temp;
        cout << '#' << test_case << ' ' << result << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}