#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[100];
int n;
void in(int k) {
	for (int i = 0; i <k; i++)
		cout << a[i] << "+";
	cout << a[k]<<endl;
}
int total(int k) {
	int S = 0;
	for (int i = 0; i < k; i++)
		S += a[i];
	return S;
}
void Try(int k) {
	for(int i=1;i<=n;i++)
		if (total(k) + i <= n and a[k-1] <= i)
		{
			a[k] = i;
			if (total(k + 1) == n) in(k);
			else Try(k + 1);
		}
}
int main()
{
	cin >> n;
	Try(0);
	return 0;
}
