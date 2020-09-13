#include <iostream>
#include <vector>
using namespace std;
int a[100006], b[100006];
int n;
int k = 3;
int res[10005];
void quicksort1(int l, int r) {
	int i = l; int j = r;
	int mid = (l + r) / 2;
	while (i <= j)
	{
		while (a[i] < a[mid]) i += 1;
		while (a[j] > a[mid]) j -= 1;
		if (i <= j) {
			swap(a[i], a[j]);
			swap(b[i], b[j]);
			i += 1;
			j -= 1;
		}
	}
	if (i < r) quicksort1(i, r);
	if (l < j) quicksort1(l, j);
}
void quicksort2(int l, int r) {
	int i = l; int j = r;
	int mid = (l + r) / 2;
	while (i <= j)
	{
		while (b[i] < b[mid]) i += 1;
		while (b[j] > b[mid]) j -= 1;
		if (i <= j) {
			swap(a[i], a[j]);
			swap(b[i], b[j]);
			i += 1;
			j -= 1;
		}
	}
	if (i < r) quicksort2(i, r);
	if (l < j) quicksort2(l, j);
}
void binary_search1(int x) {
	int r = n - 1, l = 0;
	while (l <= r)
	{
		int mid = (r + l) / 2;
		if (a[mid] == x)
		{
			res[k] = b[mid];
			k += 2;
			break;
		}
		else if (a[mid] >x)
			r = mid - 1;
		else l = mid + 1;
	}
}
void binary_search2(int x) {
	int r = n - 1, l = 0;
	while (l <= r)
	{
		int mid = (r + l) / 2;
		if (b[mid] == x)
		{
			res[k] = a[mid];
			k -= 2;
			break;
		}
		else if (b[mid] > x)
			r = mid - 1;
		else l = mid + 1;
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	quicksort1(0, n - 1);	
	res[1] = b[0];
	for (int i = 1; i < n; i++)
	{
		binary_search1(res[k-2]);
	}
	
	quicksort2(0, n - 1);
	res[n - 2] = a[0];
	k = n - 2;
	for (int i = 1; i < n; i++)
	{
		binary_search2(res[k + 2]);
	}
	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	return 0;
}