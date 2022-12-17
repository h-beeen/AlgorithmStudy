#include <iostream>
using namespace std;

int h, m = 0;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> h >> m;
	m -= 45;
	if(m < 0)
	{
		h--;
		m += 60;
	}
	if(h < 0)
		h = 23;
	if(h > 23)
		h = 0;
	cout << h << ' ' << m;
}