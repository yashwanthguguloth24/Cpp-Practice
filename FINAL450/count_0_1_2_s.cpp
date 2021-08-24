// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

// Directly using counts and updating the array.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;
        for(int i = 0;i<n;i++)
        {
            if(a[i] == 0)
            {
                count0++;
            }
            else if(a[i] == 1)
            {
                count1++;
            }
            else
            {
                count2++;
            }
        }
        int i = 0;
        while(i<n)
        {
            while(count0)
            {
                a[i] = 0;
                i++;
                count0--;
            }
            while(count1)
            {
                a[i] = 1;
                i++;
                count1--;
            }
            while(count2)
            {
                a[i] = 2;
                i++;
                count2--;
            }
        }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends

// *********************** DUTCH NATIONAL FLAG APPROACH ***********************
class Solution
{
    public:
    void swap(int &a,int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void sort012(int a[], int n)
    {

        int i = 0;
        int j = 0;
        int k = n-1;
        while(i<=k)
        {
            if(a[i] == 0)
            {
                swap(a[i],a[j]);
                i++;
                j++;
            }
            else if(a[i] == 1)
            {
                i++;
            }
            else if(a[i] == 2)
            {
                swap(a[i],a[k]);
                k--;
            }
        }

    }
    
};


















