// https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1

// easy xor

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
        int x = 1;
        int y = a^b;
        int ans = 0;
        while(x<=y)
        {
            if(x&y)
            {
                ans++;
            }
            x = x<<1;
        }
        return ans;
        
    }
};
