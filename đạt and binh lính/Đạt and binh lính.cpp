#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,q,luu=0;
vector<int> a;
int binary_search(int x) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (a[mid] <= x) {
			l = mid + 1;
			luu = mid;
		}
		else r = mid - 1;
	}
	return luu;
}
int main()
{
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int x;
		cin >> x;
		luu = binary_search(x);
		cout <<endl<< luu + 1 << " ";
		int s = 0;
		for (int i = 0; i <= luu; i++)
		{
			s += a[i];
		}
		cout << s << endl;
	}
}