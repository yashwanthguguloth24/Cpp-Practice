//https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1#

// Approach : creating hash array to store 256 characters and using frequency to check if they are equal or not

// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        int hash_s1[MAX_CHARS] = {0};
        int hash_s2[MAX_CHARS] = {0};
        int N = str1.length();
        int M = str2.length();
        if(N != M)
        {
            return 0;
        }
        for(int i = 0;i<N;i++)
        {
            hash_s1[str1[i]]++;
            hash_s2[str2[i]]++;
            if(hash_s1[str1[i]] != hash_s2[str2[i]])
            {
                return 0;
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends
