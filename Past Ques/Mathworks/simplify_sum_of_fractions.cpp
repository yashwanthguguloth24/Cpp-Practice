#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
} 
int main()
{
    string s = "358/472+301/417";
    // 722/148+360/176
    // 978/1212+183/183
    // 358/472+301/417
    int a = 0;
    int i = 0;
    while(s[i] != '/')
    {
        a = a*10 + (s[i]-'0');
        i++;
    }
    i++;
    int b = 0;
    while(s[i] != '+')
    {
        b = b*10 + (s[i]-'0');
        i++;
    }  
    i++;
    int c = 0;
    while(s[i] != '/')
    {
        c = c*10 + (s[i]-'0');
        i++;
    }  
    i++;
    int d = 0;
    while(i < s.length())
    {
        d = d*10 + (s[i]-'0');
        i++;
    }  
    int num = a*d+c*b;
    int den = b*d;
    int g = gcd(num,den);
    num = num/g;
    den = den/g;
    cout << num << "/" << den << endl;

    return 0;
}
