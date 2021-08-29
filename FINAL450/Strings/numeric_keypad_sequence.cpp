// https://www.geeksforgeeks.org/convert-sentence-equivalent-mobile-numeric-keypad-sequence/

// simple storing and output

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    string s;
    cin >> s;
    vector<string> keySQmap = {"2","22","222",
                                "3","33","333",
                                "4","44","444",
                                "5","55","555",
                                "6","66","666",
                                "7","77","777","7777",
                                "8","88","888",
                                "9","99","999","9999"
                                };
    string ans = "";
    for(int i = 0;i<s.length();i++)
    {
        ans += keySQmap[s[i]-'A'];
    }
    cout << ans << endl;
    return 0;
}
