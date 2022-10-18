#include <iostream>
using namespace std;

int n, m, temp;
int arr[10];
int num[10];
bool isused[10];

void func(int k) { // 현재 k개까지 수를 택했음.
  if (k == m) {
    for (int i = 0; i < m; ++i) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }
  int tmp = 0;  // 중복 수열인지 확인 하기 위해 필요한 임시 변수
  for (int i = 0; i < n; ++i) {
    if (!isused[i] && tmp != num[i]){ // 이전 수열의 마지막 항과 새로운 수열의 마지막 항이 같으면 중복 수열
      isused[i] = true;
      arr[k] = num[i];
      tmp = arr[k];
      func(k + 1);
      isused[i] = false;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> num[i];

	for(int i = 0; i < n; ++i)
	{
		for(int j = i; j < n; ++j)
		{
			if(num[i] > num[j])
			{
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;		
			}	
		}
	}
	func(0);
}
