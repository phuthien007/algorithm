#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
int a, b, n;
int main()
{
    cin >> a >> b >> n;
    int x = 1;
    int k = (pow(a, x) - b) / n;
    while (  k != (pow(a, x) - b) / n )
    {
        x += 1;
        k = (pow(a, x) - b) / n;
        if (k >= n) { cout << -1; return 0; }
    }
    cout << x;
    return 0;
}
