// https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

// https://www.youtube.com/watch?v=g6OxU-hRGtY


// Using previous value bits and generating a formula


class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int nearestpow2(int n)
    {
        int x = 0;
        while((1<<x) <= n)
        {
            x++;
        }
        return (x-1);
    }
    int countSetBits(int n)
    {
        if(n == 0)
        {
            return 0;
        }
        // Your logic here
        int x = nearestpow2(n);
        int top2n = x*(1<< (x-1));
        int down1s = n - (1<<x) + 1;
        int to_find = countSetBits((n - (1<<x)));
        return (top2n+down1s+to_find);
        
        
    }
};
