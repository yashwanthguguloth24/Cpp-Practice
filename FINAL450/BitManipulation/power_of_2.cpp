// https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1

// simple xor

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        long long x = 1;
        while(x<=n)
        {
            if((n^x) == 0)
            {
                return 1;
            }
            x = x << 1;
        }
        return 0;
    }
    
};
