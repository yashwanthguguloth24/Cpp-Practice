// https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1#


// References:
// https://tutorialspoint.dev/algorithm/greedy-algorithms/minimum-swaps-bracket-balancing
// https://www.youtube.com/watch?v=Ylz6mwghDrU

/*
Based on the fact that, for a balanced case count of opening braces is always greater than or equal to count of closing braces
We need to update the correction if closing>opening and add it answer when we encounter opening brace as we are looking for it to correct
*/

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        // code here 
        int correction = 0;
        int opening = 0;
        int closing = 0;
        int ans = 0;
        for(int i = 0;i<S.length();i++)
        {
            if(S[i] == ']')
            {
                closing++;
                correction = closing-opening;
            }
            else
            {
                opening++;
                if(correction>0)
                {
                    ans+= correction;
                    correction--;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends
