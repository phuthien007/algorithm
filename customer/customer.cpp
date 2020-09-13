#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef struct {
	int x;
	int y;
}Data;
int n;
Data d1[1000];
void bubble() {
	for(int i=0;i<2*n;i++)
		for(int j=i+1;j<2*n;j++)
			if (d1[i].x > d1[j].x)
			{
				Data temp;
				temp = d1[i];
				d1[i] = d1[j];
				d1[j] = temp;
			}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Data temp;
		cin >> temp.x; temp.y = 1;
		d1[i] = temp;
		cin >> temp.x; temp.y = -1;
		d1[i+n] = temp;
	}
	bubble();
	int res = 0, ans = 0;
	for (int i = 0; i <= 2 * n; i++)
	{
		res += d1[i].y;
		ans = max(ans, res);
	}
	cout << ans;
	return 0;
}
/*
có thể dùng cấu trúc dữ liệu pair nhưng do mình không quen nên không sử dụng mà thay vào đó là tự tạo 1 kiểu dữ liệu riêng qua trúct
*/