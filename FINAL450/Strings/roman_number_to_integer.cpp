// https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1#

// simple iteration in a loop to get answer.


// { Driver Code Starts
// Initial template for C++

// Program to convert Roman Numerals to Numbers
#include <bits/stdc++.h>
using namespace std;

// Returns decimal value of roman numaral
int romanToDecimal(string &);

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
}// } Driver Code Ends


// User fuunction teemplate for C++

// str given roman number string
// Returns decimal value of roman numaral
int romanToDecimal(string &str) {
    // code here
    map<char,int> m;
    int n = str.length();
    m.insert({'I', 1 });
    m.insert({'V', 5 });
    m.insert({'X', 10 });
    m.insert({'L', 50 });
    m.insert({'C', 100 });
    m.insert({'D', 500 });
    m.insert({'M', 1000 });
    
    if(n == 1)
    {
        return m[str[0]];
    }
    // char c = str[n-1];
    // cout << c << endl;
    int val = m[str[n-1]];
    for(int i = n-2;i>=0;i--)
    {
        if(m[str[i]]>=m[str[i+1]])
        {
            val += m[str[i]];
        }
        else
        {
            val -= m[str[i]];
        }
    }
    return val;
    
    
}
