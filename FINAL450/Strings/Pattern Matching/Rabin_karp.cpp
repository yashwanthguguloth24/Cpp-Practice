// https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/

// Using hashing to reduce the string checking of patterns

#include<iostream>
#include<math.h>
using namespace std;

int prime = 11;

int reCalcHash(string s,int oldInd,int newInd,int prevHash,int hashLen)
{
    int newHash = prevHash-s[oldInd];
    newHash = newHash/prime;
    newHash += s[newInd]*pow(prime,hashLen-1);
    return newHash;
}




int CalcHash(string s,int end)
{
    int hash = 0;
    for(int i = 0;i<=end;i++)
    {
        hash += s[i]*pow(prime,i);
    }
    return hash;

}


bool CheckEqual(string s1,int start1,int end1,string s2,int start2,int end2)
{
    int i = start1;
    int j = start2;
    while(i<=end1 && j<=end2)
    {
        if(s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}


void RabinKarpPatternMatch(string text,string pattern)
{
    int N = text.length();
    int M = pattern.length();
    int textHash = CalcHash(text,M-1);
    int patternHash = CalcHash(pattern,M-1);
    cout << "pattern hash : " << patternHash << endl;
    for(int i = 0;i<N-M+1;i++)
    {
        cout << "text hash : " << textHash << ",  "<< i << endl;
        if(textHash == patternHash && CheckEqual(text,i,i+M-1,pattern,0,M-1))
        {
            cout << "Match found at index : " << i << endl;
        }
        if(i<N-M)
        {
            textHash = reCalcHash(text,i,i+M,textHash,M);
        }
    }
}



int main()
{
    string text = "GEEKSFORGEEKS";
    string pat = "GEEK";
    RabinKarpPatternMatch(text,pat);
    return 0;
}
