// https://www.geeksforgeeks.org/find-the-k-th-permutation-sequence-of-first-n-natural-numbers/

// using mathematical method to divide them to boxes and iterate

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int factorial(int n)
{
    // single line to find factorial
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}

string kthPerm(int n,int k)
{
    string ans = "";
    vector<int> nums;
    for(int i = 1;i<=n;i++)
    {
        nums.push_back(i);
    }
    while(n)
    {
        int ind = (k/factorial(n-1));
        if(k%(factorial(n-1)) == 0)
        {
            ind--;
        }
        char ch = '0'+nums[ind];
        ans += ch;
        nums.erase(nums.begin()+ind);
        k = k - factorial(n-1)*ind;
        n--;
    }
    return ans;
}



int main()
{
    cout << kthPerm(9,2)<<endl;
    return 0;
}
