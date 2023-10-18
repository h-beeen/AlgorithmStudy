/**
 * Problem - 2805. 농작물 수확하기
 * 정답률 - 76.90
 * 난이도 - D3
 * 17:03 Start
 */


#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, result, center, tcs;
int land[55][55], visit[55][55];

struct el {
    int y;
    int x;
    int depth;
};

el temp;
el temp2;
string str;
queue<el> q;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {-1, 1, 0, 0};

int main(void) {

    cin >> tcs;

    for (int tc = 1; tc <= tcs; tc++) {

        memset(land, 0 , sizeof(land));
        memset(visit, 0 , sizeof(visit));

        while (!q.empty())
            q.pop();

        result = 0;

        cin >> N;


        for (int y = 0; y < N; y++) {
            cin >> str;
            for (int x = 0; x < N; x++)
                land[y][x] = str[x] - 48;
        }

        center = N / 2;
        temp.y = center;
        temp.x = center;
        temp.depth = 0;
        q.push(temp);
        visit[center][center] = 1;

        while (!q.empty()) {
            temp = q.front();
            q.pop();

            result += land[temp.y][temp.x];
            if (temp.depth < center) {
                for (int dir = 0; dir < 4; dir++) {
                    int ny = temp.y + dy[dir];
                    int nx = temp.x + dx[dir];

                    if (visit[ny][nx] || ny >= N || nx >= N || nx < 0 || ny < 0)
                        continue;

                    temp2.y = ny;
                    temp2.x = nx;
                    temp2.depth = temp.depth + 1;
                    q.push(temp2);
                    visit[ny][nx] = 1;
                }
            }
        }
        cout << '#' << tc << ' '<< result << '\n';
    }
    return 0;
}

