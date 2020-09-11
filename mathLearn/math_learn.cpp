#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr(1e6+1,0);
int n;
void creat() {
	arr[0] = arr[1] = -1;
	for(int i=2;i<sqrt(1e6);i++ )
		if (arr[i] == 0) {
			arr[i] = 1;
			for (int j = i*i; j <= 1e6; j += i)
				arr[j] += arr[i]+1;
		}
}
/*
có 1 cách khác là dùng luôn công thức nhưng mình không biết chứng minh, có thể liệt kê để tìm công thức thì bài toán sẽ theo O(1)
còn cách mình làm là O(n)
n chẵn 8 n-8
lẻ 9 n-9
 */
int main()
{
	cin >> n;
	creat();
	for(int i=4;i<=n;i++)
		if (arr[i] >= 2 && arr[n - i] >= 2)
		{
			cout << i << " " << n - i<<endl;
			break;
		}
	return 0;
}
