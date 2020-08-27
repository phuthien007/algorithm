#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef struct {
	int x;
	int y;
}Data;
char a[1001][1001];
int n,m;
Data d,c;
void Read() {
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'B')
			{
				d.x = i;
				d.y = j;
				a[i][j] = '.';
			}
			else if (a[i][j] == 'C')
			{
				c.x = i;
				c.y = j;
				a[i][j] = '.';
			}
		}
}
int a_x[] = { -1,0,0,1 };
int a_y[] = { 0,-1,1,0 };
bool kt[1001][1001];
int res[1001][1001];
void BFS()
{
	queue<Data> q;
	Data temp;
	temp.x = d.x;
	temp.y = d.y;
	q.push(temp);
	res[temp.x][temp.y] = 0;
	kt[temp.x][temp.y] = true;
	while (!q.empty())
	{
		Data u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x1 = a_x[i] + u.x;
			int y1 = a_y[i] + u.y;
			if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && a[x1][y1] == '.' && kt[x1][y1] == false)
			{
				kt[x1][y1] = true;
				res[x1][y1] = res[u.x][u.y] + 1;
				temp.x = x1;
				temp.y = y1;
				q.push(temp);
			}
		}
	}
}
int main() {
	Read();
	BFS();
	cout << res[c.x][c.y];
	return 0;
}