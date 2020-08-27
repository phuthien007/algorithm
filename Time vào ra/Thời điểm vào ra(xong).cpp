#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m;
vector<int> arr[10005];
void Read() {
	cin >> n;
	for (int i = 1; i <n; i++)
	{
		int x, y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
}
bool kt[10005];
int time_in[10005];
int time_out[10005];
int time = 0;
void DFS(int x) {
	time_in[x] = time;
	time += 1;
	kt[x] = true;
	for (int i : arr[x]) {
		if (kt[i] == false)
		{
			DFS(i);
		}
	}
	time_out[x] = time;
}
void out() {
	cout << "T... in/out\n";
	for (int i = 1; i <= n; i++)
		cout << time_in[i] << " ";
	cout << endl;
	for (int i = 1; i <= n; i++)
		cout << time_out[i] << " ";
}
int main()
{
	Read();
	DFS(1);
	out();
}
