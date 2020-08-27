#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m;
vector<int> a[10005];
void Read() {
	cin >> n>>m;
	for (int i = 1; i <=m; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
}
bool kt[10005];
int dd = 0;
vector<int> res[10005];
bool check(int x,int k) {
	for (int i : res[x])
		if (k == i)
			return false;
	return true;
}
void DFS(int i) {
	kt[i] = true;
	if(check(dd,i)==true)
		res[dd].push_back(i);
	for (int k : a[i])
	{
		if (kt[k] == false)
		{
			kt[k] == true;
			if(check(dd,k) == true)
				res[dd].push_back(k);
			DFS(k);
		}
	}
}
int main()
{
	Read();
	for(int i=1;i<=n;i++)
		if (kt[i] == false)
		{
			dd += 1;
			DFS(i);
		}
	for (int i = 1; i <= dd; i++)
	{
		cout << "GRAPH " << i << ": "<<res[i].size()<<" ";
		for (int k : res[i])
			cout << k << " ";
		cout << endl;
	}
}
