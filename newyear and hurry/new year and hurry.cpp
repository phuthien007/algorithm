#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, t,l,luu;
vector<int> a;
int search_binary(int x) {
	int l = 1; int r = n ;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (a[mid] <= x)
		{
			luu = mid;
			l = mid + 1;
		}
		else r=mid-1;
	}
	return luu;
}
int main()
{
	cin >> n >> t;
	l = 240 - t;
	a.resize(n + 1);
	a[0] = 0;
	for (int i = 1; i <= n; i++)
		a[i] = (i) * 5+ a[i-1];
	luu = search_binary(l);
	cout << luu ;
	/*if (n < int((sqrt(1 + 8 * l / 2) - 1) / 2))
		cout << n;
	else cout << int((sqrt(1 + 8 * l / 2) - 1) / 2)-1;*/
}