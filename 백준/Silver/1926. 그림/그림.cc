#include <iostream>
#include <queue>
using namespace std;

int board[505][505];
int vis[505][505];
int n, m, area = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int num = 0;
int mx = 0;

int main (void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];         // 보드에 입력 값 모두 입력



    for(int i = 0; i < n; i++)          // 첫 스타트 보드 위치 탐색
    {                                   // 한 지도가 끝나면, 다음 지도 위치 탐색
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 0 || vis[i][j] == 1) // 보드가 색칠되어 있지 않거나, 기방문한 노드면
                continue;                       // continue로 빠져나가자.

                num++;                          // 전체 그림의 수를 하나 더하고
                queue<pair<int,int> > q;       // q 새로 생성
                vis[i][j] = 1;                // 나 방문했어요! 지금 현 위치!
                q.push(make_pair(i,j));         // q 스택에 현 노드 생성

                area = 0;
                while(!q.empty())                // 연결되있는 이번 지도가 끝날 때 까지 // BFS
                {
                    area++;
                    pair<int, int> temp = q.front(); // temp에 q 스택의 내용 저장
                    q.pop();                           // 큐에서 제거

                    for(int dir = 0; dir < 4; dir++)
                    {
                        int nx = temp.first + dx[dir];
                        int ny = temp.second + dy[dir];

                        if(nx < 0 || nx > n || ny < 0 || ny > m)
                            continue;
                        if(board[nx][ny] == 0 || vis[nx][ny])
                            continue;
                        vis[nx][ny] = 1;
                        q.push(make_pair(nx,ny));

                    }
                }
                if(mx <= area)
                    mx = area;
        }
    }
    cout << num << '\n' << mx;
}