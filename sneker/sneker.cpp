#include <iostream>
#include <vector>
using namespace std;
long long a, b,c, d;
void change(vector<vector<char>> &a, int b) {
	vector<vector<char>> arr(a);
	for (int i = 0; i < a.size(); i++)
	{
		
		a[i].resize(a[i].size()*b);
		for (int j = 0; j < arr[i].size(); j++)
		{
			a[i][2*j] = arr[i][j];
			a[i][2*j + 1] = arr[i][j];
		}
	}
}
int main() {
	cin >> a >> b >> c>>d;
	vector<vector<char>> arr;
	arr.resize(a);
	for (int i = 0; i < a; i++)
	{
		arr[i].resize(b);
		for (int j = 0; j < b; j++)
		
			cin >> arr[i][j];
	}
	change(arr, d);
	for (int i = 0; i < arr.size(); i++)
	{
		for (int k = 0; k < c; k++)
		{
			for (int j = 0; j < arr[i].size(); j++)
				cout << arr[i][j];
			cout << endl;
		}
	}
	return 0;
}