#include <iostream>
#include <vector>
using namespace std;

vector <int> v;
int k, temp;

int main (void)
{
	cin >> k;
	for(int i = 0; i < k; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	cout << *min_element(v.begin(), v.end()) << ' ' << *max_element(v.begin(), v.end());
}