#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int t, n,m;
vector<int> arr[1003];
void Read() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
}
bool kt[1003];
void BFS() {
	queue<int> q;
	q.push(1);
	kt[1] = true;
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
int main() {
	int k = -1;
	Read();
	BFS();
	for (int i = 1; i <= n; i++)
		if (kt[i] == false)
		{
			k = 1;
			break;
		}
	if (k == -1)
		cout << 0 ;
	else {
		for (int i = 1; i <= n; i++)
			if (kt[i] == false)
			{
				cout << i << endl;
			}
	}
	return 0;
}