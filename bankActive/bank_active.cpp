#include <iostream>
#include <vector>
using namespace std;
int t, d, a, m, b, x;
int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> d >> a >> m >> b >> x;
		if (d >= x)
			cout << 0 << endl;
		else {
			int res = (x - d) / (m * a + b);
			cout << res * (m + 1) + ((x - d - res * (m * a + b)) / a +1)<<endl;
		}
	}


}