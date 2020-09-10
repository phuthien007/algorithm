#include <iostream>
#include <vector>
using namespace std;
long long a, n, p;
int main() {
	cin >> a >> n >> p;
	long long temp = 1;
	while (n)
	{
		if (n % 2 == 1)
			temp *= a%p;
		n /= 2;
		a *= a%p;
	}
	cout << temp%p;
	return 0;	
}