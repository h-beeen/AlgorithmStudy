#include <iostream>
#include <string>
using namespace std;

string a, b;
int main(void)
{
	cin >> a >> b;
	if (a[2] > b[2])
		cout << a[2] << a[1] << a[0];
	else if (a[2] < b[2])
		cout << b[2] << b[1] << b[0];
	else
	{
		if (a[1] > b[1])
			cout << a[2] << a[1] << a[0];
		else if (a[1] < b[1])
			cout << b[2] << b[1] << b[0];
		else
		{
			if (a[0] > b[0])
				cout << a[2] << a[1] << a[0];
			else
				cout << b[2] << b[1] << b[0];
		}
	}
	
	
}