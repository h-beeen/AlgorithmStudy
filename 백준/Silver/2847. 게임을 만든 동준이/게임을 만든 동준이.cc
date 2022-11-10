#include <iostream>
#include <algorithm>
using namespace std;

int n, k[105], cnt;
int main(void)
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> k[i];

    reverse(k, k+n);

    for(int i = 1; i < n; i++)
    {
        while(k[i] >= k[i-1])
        {
            cnt++;
            k[i]--;
        }
    }
    cout << cnt;
}