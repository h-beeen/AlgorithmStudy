#include <iostream>
#include <vector>
using namespace std;

vector <int> v(9);
int k, res = 0;
string s;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> k >> s;
	for(int i = 0; i < k; i++)
		v[s[i] - '0']++;
	
	for(int i = 1; i < 10; i++)
		res += (v[i] * i);
	cout << res;
}