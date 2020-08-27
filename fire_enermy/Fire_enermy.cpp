#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int t, n, a[103][103];
vector<int> arr[103];
void Read() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
}
void init() {
	for (int i = 1; i <= n; i++)
		if (!arr[i].empty())
			arr[i].clear();
}
void change(int x) {
	int temp[103][103];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i == x || j == x)
				temp[i][j] = 0;
			else temp[i][j] = a[i][j];
	init();
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
		{
			if (temp[i][j] == 1)
			{
				arr[i].push_back(j);
				arr[j].push_back(i);
			}
		}
}
bool kt[103];
void reset() {
	for (int i = 1; i <= n; i++)
		kt[i] = false;
}
void BFS(int u) {
	queue<int> q;
	q.push(u);
	kt[u] = true;
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int i : arr[v])
		{
			if (kt[i] == false)
			{
				kt[i] = true;
				q.push(i);
			}
		}
	}
}
int Count(int x) {
	int res = 0;
	init();
	change(x);
	reset();
	for (int i = 1; i <= n; i++)
	{
		if (kt[i] == false and i != x)
		{
			BFS(i);
			res += 1;
		}
	}
	return res;
}
int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		Read();
		int b = Count(0);
		int d = 0, luu = 0;
		for (int i = 1; i <= n; i++)
			if (d < Count(i))
			{
				d = Count(i);
				luu = i;
			}
		cout << ((b == d) ? 0 : luu) <<endl;
	}
	return 0;
}