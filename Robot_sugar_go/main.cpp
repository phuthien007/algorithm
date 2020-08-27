#include <iostream>
#include <vector>
#include <queue>
#define d 2147483647
using namespace std;
int n;
bool kt[1003][1003];
long long a[1003][1003];
char arr[1003][1003];
void Read() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
}
long long Count() {
	a[1][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (arr[i][j] == '.')
				a[i][j] = (a[i - 1][j] + a[i][j - 1]) %d;
	return a[n][n];
}
int a_x[] = { -1,0,1,0 };
int a_y[] = { 0,1,0,-1 };
typedef struct {
	int x;
	int y;
}Data;
void BFS() {
	queue<Data> q;
	Data temp;
	temp.x = 1;
	temp.y = 1;
	kt[1][1] = true;
	q.push(temp);
	while (!q.empty())
	{
		Data u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x1 = a_x[i] + u.x;
			int y1 = a_y[i] + u.y;
			if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= n && arr[x1][y1] == '.' && kt[x1][y1] == false)
			{
				temp.y = y1;
				temp.x =x1;
				q.push(temp);
				kt[x1][y1] = true;
			}
		}
	}
}
int main() {
	Read();
	long long x = Count();
	if (x != 0)
		cout << x;
	else {
		BFS();
		if (kt[n][n] == true)
			cout << "THE GAME IS A LIE";
		else
			cout << "INCONCEIVABLE";
	}

	return 0;
}