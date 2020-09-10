#include <iostream>
#include <vector>
#include <string>
using namespace std;
int a, b,t;
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        int sl, even;
        sl = (b - a + 1) * (b + a) / 2;
        if (a % 2 == 0) a += 1;
        if (b % 2 == 0) b -= 1;
        even = ((b - a) / 2 + 1) * (b + a) / 2;
        cout << sl - 2 * even << endl;
    }
    return 0;
}
