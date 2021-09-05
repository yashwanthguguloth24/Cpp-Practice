// https://www.geeksforgeeks.org/searching-array-adjacent-differ-k/

// make jump in traversal and prove that jump is safe


#include<bits/stdc++.h>
using namespace std;

int search_val(int arr[],int x,int k,int n)
{
    int i = 0;
    while(i<n)
    {
        if(arr[i] == x)
        {
            return i;
        }
        else{
            i = i + max(1,abs(arr[i]-x)/k);
        }
    }
    return -1;
}


int main()
{
    int arr[] = {2, 4, 5, 7, 7, 6};
    int x = 6;
    int k = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << search_val(arr,x,k,n) << endl;
    return 0;
}
