#include <iostream>
#include <vector>
using namespace std;
int a[10005], n;
bool check(int n,int k) {
    for (int i = 0; i < k; i++)
    {
        if (a[i] + i == n + k) return false;
        if (a[i] - i == n - k) return false;
        if (a[i] == n) return false;
    }
    return true;
}
void in() {
    for (int i = 0; i < n; i++)
        cout << a[i] + 1 << " ";
    cout << endl;
}
void Try(int k) {
    for (int i = 0; i < n; i++)
        if (check(i, k) == true)
        {
            a[k] = i;
            if (k+1 == n)
                in();
            else Try(k+1);
        }
}
int main()
{
    cin >> n;
    Try(0);
    return 0;
}
