#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <deque>
using namespace std;
deque<char> s;
void in() {
    while (!s.empty()) {
        cout << s.front();
        s.pop_front();
    }
}
int main()
{
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '\n')
            break;
        if (str[i] == '<')
        {       if (s.empty() != true)
                s.pop_back();
        }
        else s.push_back(str[i]);    
    }
    in();
    return 0;
}
