#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

string s;
int breakingCnt;
int n, m, board[1005][1005];
bool vis[15][1005][1005];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

typedef struct {
    int x;
    int y;
    int distance;
    int breaking;
} pos;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> breakingCnt;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++)
            board[i][j] = s[j] - '0';
    }


    queue <pos> Q;
    pos temp = {0, 0, 1, 0};
    Q.push(temp);

    while(!Q.empty())
    {
        temp = Q.front(); Q.pop();
        if(temp.x == n-1 && temp.y == m-1) {
            cout << temp.distance;
            return 0;
        }

        for(int dir = 0; dir < 4; dir++){
            int nx = temp.x + dx[dir];
            int ny = temp.y + dy[dir];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            // 벽인데 부술 카운트가 존재하고, 현재 카운트로 방문한 적 없는 경우
            if(board[nx][ny] == 1 && temp.breaking < breakingCnt && !vis[temp.breaking][nx][ny]){
                pos temp2 = {nx, ny, temp.distance + 1, temp.breaking + 1};
                vis[temp.breaking][nx][ny] = true;
                Q.push(temp2);
            }

            // 일반 길인데 방문한 적 없는 경우
            if(!board[nx][ny] && !vis[temp.breaking][nx][ny]){
                pos temp2 = {nx, ny, temp.distance + 1, temp.breaking};
                vis[temp.breaking][nx][ny] = true;
                Q.push(temp2);
            }
        }
    }

    cout << -1;
    return 0;
}