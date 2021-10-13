#include<bits/stdc++.h>
using namespace std;

string solve(string s)
{
    int n = s.length();
    string res = "";
    int i = 1;
    int cnt = 1;
    char p = s[0];
    while(i < n)
    {
        while(i<n && p == s[i])
        {
            i++;
            cnt++;
        }
        
        res += p;
        if(cnt != 0) res += to_string(cnt);
        p = s[i];
        cnt = 0;
    }
    return res;
}



int main()
{
    string s = "yyyyyylllllliiiiinnnnaaaaaaaaayyyyy";
    cout << solve(s) << endl;
    return 0;
}
