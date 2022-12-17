#include <iostream>
#include <vector>
using namespace std;
vector <int> v(9);

int main(void)
{
	for(int i = 0; i < 9; i++)
		cin >> v[i];
	int a = max_element(v.begin(), v.end()) - v.begin();
	cout << v[a] << '\n' << a + 1;
}