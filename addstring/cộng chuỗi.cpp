#include <math.h>
#include <iostream>
#include <string>
using namespace std;
string add(string s1, string s2)
{
	int len;
	string res = "";
	s1.length() > s2.length() ? len = s1.length() : len = s2.length();
	while (s1.length() < len)
		s1 = '0' + s1;
	while (s2.length() < len)
		s2 = '0' + s2;
	int remember = 0;
	for (int i = len-1; i >=0; i--)
	{
		int n1 = int(s1[i] - 48);
		int n2 = int(s2[i] - 48);
		int temp = n1 + n2+remember;
		remember = temp / 10;
		res = char(temp % 10 + '0') + res;
	}
	if (remember != 0)
		res = char(remember + '0') + res;
	return res;
}
int main()
{
	cout << add("22", "92");
}