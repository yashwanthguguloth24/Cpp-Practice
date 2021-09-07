// https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1#


// using stable sort(USED FOR DUPLICATES ORDERING)


class Solution{
    public:
    // static int setBits(int N) 
    // {
    //     int a = 1;
    //     int cnt = 0;
    //     while(a<=N)
    //     {
    //         if((N&a) > 0)
    //         {
    //             cnt++;
    //         }
    //         a = a<<1;
    //     }
    //     return cnt;
    // }
    
    static bool custom(int x,int y)
    {
        int cnt1 = 0;
        int cnt2 = 0;
        while(x)
        {
            cnt1 += (x&1);
            x = x>>1;
        }
        while(y)
        {
            cnt2 += (y&1);
            y = y>>1;
        }
        return (cnt1>cnt2);
    }
    
    
    
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        stable_sort(arr,arr+n,custom);
    }
};
