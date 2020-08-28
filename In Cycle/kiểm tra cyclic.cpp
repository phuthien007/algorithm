#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<int> arr[10005];
void Read() {
	cin >> n>>m;
	for (int i = 1; i <=m; i++)
	{
		int x, y;
		cin >> x >> y;
		arr[x].push_back(y);
	}
}
int visit[10005];
bool cycle = false;
vector<int> res;
int luu;
void in(int x,int luu) {
	cout << x << " ";
	for (int i : arr[x])
		if (visit[i] == 1 and i != luu)
			in(i, luu);
		else if (i == luu)
		{
			cout << i << " ";
			exit(0);
		}
}
void dfs(int u) {
	visit[u] = 1;
	for (int i : arr[u]) {
		if (visit[i] == 0)
		{
			dfs(i);
		}
		else if (visit[i] == 1)
		{
			cycle = true;
			luu = i;
			in(i,luu);
			
		}
	}
	visit[u] = 2;
}
int main()
{
	Read();
	dfs(1);
	if (cycle == false)
		cout << "Acyclic";
	else {
		for (int i = 1; i <= n; i++)
			cout << visit[i] << " ";
	}
	return 0;

}
