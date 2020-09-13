#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
int n;
int main()
{
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int res = 0;
	for (int i = 0; i < n - 1; i++)
		if (a[i] > a[i + 1])
			res += 1;
	cout << res;
}
