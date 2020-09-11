#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, a=0, b=1;
int main()
{
	cin >> n;
	int count = 0;
	while (count < n) {
		int temp = a + b;
		a = b;
		b = temp;
		count += 1;
	}
	cout << a * b;
	return 0;
}
