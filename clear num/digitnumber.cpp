#include <iostream>
#include <vector>
#include <string>
using namespace std;
int a[10005], n,time=0;
bool check(int n) {
    while (n >9 and time != 1e6)
    {
        string temp = to_string(n);
        n = 0;
        time += 1;
        for (int i = 0; i < temp.length(); i++)
            n += int(temp[i] - 48)* int(temp[i] - 48);
    }
    if (time == 1e6 || n!=1) return false;
    return true;
}
int main()
{
    cin >> n;
    cout << check(n);
    return 0;
}
