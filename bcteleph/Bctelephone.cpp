#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int t, n;
vector<string> a;
int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		a.resize(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		int kt = 0;
		if (a[n - 1].length() <= 10)
			for (int i = 0; i < n; i++)
			{
				int l = i + 1, r = n - 1;
				while (l <= r) {
					int mid = (r + l) / 2;
					string s = a[mid].substr(0, a[i].length());
					if (a[i] == s)
					{
						kt = 1;
						break;
					}
					else if (a[i] < s)
						l = mid + 1;
					else r = mid - 1;
				}
				if (kt != 0) break;
			}
		else kt = 1;
		if (kt != 0) cout << "NO" << endl;
		else cout << "YES" << endl;
	}

}