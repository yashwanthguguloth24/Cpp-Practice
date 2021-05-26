// https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1#

// Aprroach:

/*
Find count of all elements which are less than or equals to ‘k’. Let’s say the count is ‘cnt’
Using two pointer technique for window of length ‘cnt’, each time keep track of how many elements in this range are greater than ‘k’. Let’s say the total count is ‘bad’.
Repeat step 2, for every window of length ‘cnt’ and take minimum of count ‘bad’ among them. This will be the final answer.
*/

// Initial unoptimised code
int minSwap(int *arr, int n, int k) {
    int cnt = 0;
    for(int i = 0;i<n;i++)
    {
        if(arr[i]<=k)
        cnt++;
    }
    
    int i = 0;
    int j = cnt-1;
    int bad = n;
    while(j<n)
    {
        int temp = 0;
        for(int u = i;u<=j;u++)
        {
            if(arr[u]>k)
            temp++;
        }
        bad = min(bad,temp);
        i++;
        j++;
    }
    return bad;
    
}


// Optimized version
// reduced extra counting while sliding the window.

int minSwap(int *arr, int n, int k) {
    int cnt = 0;
    for(int i = 0;i<n;i++)
    {
        if(arr[i]<=k)
        cnt++;
    }
    
    int i = 0;
    int j = cnt-1;
    int bad = n;
    int temp = 0;
    for(int u = i;u<=j;u++)
    {
        if(arr[u]>k)
        temp++;
    }
    bad = min(bad,temp);
    i++;
    j++;
    while(j<n)
    {
        if(arr[j]>k)
        temp++;
        if(arr[i-1]>k)
        temp--;
        bad = min(bad,temp);
        i++;
        j++;
    }
    return bad;
    
}

