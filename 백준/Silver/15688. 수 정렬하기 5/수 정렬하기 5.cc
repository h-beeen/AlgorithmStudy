#include <iostream>
#include <vector>

using namespace std;

const int MXN = 2'000'000, HALF = MXN / 2;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> numcnt(MXN + 2);
  int N, t;
  cin >> N;
  while (N--) {
    cin >> t;
    numcnt[t + HALF]++;
  }
  for (int i = 0; i <= MXN; i++)
    while (numcnt[i]--) cout << i - HALF << '\n';
}