#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
int n, k;
int a[1000];
void in() {
    for (int i = 0; i < k; i++)
        cout << a[i]+1 << " ";
    cout << endl;
}
void Try(int u) {
    for(int i=0;i<n;i++)
        {
            a[u] = i;
            if (u + 1 == k) in();
            else Try(u + 1);
        }
}
int main()
{
    cin >> n >> k;
    Try(0);
    return 0;
}
