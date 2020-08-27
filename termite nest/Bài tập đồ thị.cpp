#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
vector<int> a[10005];
void Read() {
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
}
int MAX(int x) {
	int luu;
	int mx = 0;
	for (int i : a[x])
	{
		if (mx < a[i].size())
		{
			mx = a[i].size();
			luu = i;
		}
	}
	return luu;
}
int Centre() {
	int mx = 0;
	for (auto i : a)
	{
		if (mx < i.size())
		{
			mx = i.size();
		}
	}
	return mx;
}
vector<int> res;
void sol(int x) {
	for (int i = 1; i <= n; i++)
		if (i == x)
			cout << 0 << " ";
		else cout << MAX(i)<<" ";
	cout << endl;
}
int main()
{
	Read();
	for (auto i =1;i<=n;i++)
	{
		if (Centre() == a[i].size())
			res.push_back(i);
	}
	for (auto i : res)
		sol(i);
}
