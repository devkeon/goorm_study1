#include <bits/stdc++.h>
using namespace std;
string solution(string number, int k) {
    string st1;
    for(auto now : number)
    {
        while(!st1.empty() && k>0 && st1.back() < now)
        {
            st1.pop_back();
            k-=1;
        }
        st1.push_back(now);
    }
    while(k>0)
    {
        st1.pop_back();
        k--;
    }
    return st1;
}
