// https://practice.geeksforgeeks.org/problems/set-bits0143/1#

// using and operation


class Solution {
  public:
    int setBits(int N) {
        // Write Your Code here
        int a = 1;
        int cnt = 0;
        while(a<=N)
        {
            if((N&a) > 0)
            {
                cnt++;
            }
            a = a<<1;
        }
        return cnt;
    }
};
