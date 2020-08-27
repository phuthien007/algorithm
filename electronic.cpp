#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int n, m, h;
vector<int> a[10005];
vector<int> p(10005);
int b[10005];
vector<int> lev(10005, -1);
bool kt[10005];
void BFS(int u) {
	queue<int> q;
	q.push(u);
	lev[u] = 0;
	kt[u] = true;
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (auto i : a[v])
		{
			if (kt[i] == false)
			{
				kt[i] = true;
				lev[i] = lev[v] + 1;
				q.push(i);
			}
		}
	}
}
void reset(vector<int> a, bool kt[],int n) {
	for (int i = 0; i < n; i++)
	{
		a[i] = -1;
		kt[i] = 0;
	}
}
int res[10005];
void init(int res[], int n)
{
	for (int i = 0; i < n; i++)
		res[i] = 1003;
}
void sol(int res[], vector<int> a,int n)
{
	for(int i=0;i<n;i++)
		if (a[i] != -1)
		{
			if (res[i] > a[i])
				res[i] = a[i];
		}
}
int main()
{
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++)
		cin >> b[i];
	for (int i = 0; i < h; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	init(res, n);
	for (int i = 0; i < m; i++)
	{
		reset(lev, kt, n);
		BFS(b[i]);
		sol(res, lev, n);
	}
	int kq = 0;
	for (int i = 0; i < n; i++)
	{
		if (res[i] > res[kq])
			kq = i;
	}
	cout << kq;
	return 0;
}
