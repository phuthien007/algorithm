#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m,luu,kt=0;
vector<int> a;
int search_binary(int x,int l) {
	int r = n - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (a[mid] <= x)
		{
			luu = mid; kt = 1;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return luu;
}
int main() {
	cin >> n>>m;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int mx = 0;
	sort(a.begin(), a.end());
	for(int i=0;i<n-3;i++)
		for (int j = i+1 ; j < n-2; j++)
		{
			luu = search_binary(m - a[i] - a[j], j + 1);
			if (a[luu] + a[i] + a[j] > mx)
				mx = a[luu] + a[i] + a[j];
		}
	/*
	cach tren chua dung het cac truong hop
	for(int i=0;i<n-2;i++)
		for (int j = i+1 ; j < n-1; j++)
		{
			for(int k=j+1;k<n;k++)
			if (a[k] + a[i] + a[j] > mx and  a[k] + a[i] + a[j] <=m )
				mx = a[luu] + a[i] + a[j];
		}
	*/
	cout << mx;
	return 0;
}