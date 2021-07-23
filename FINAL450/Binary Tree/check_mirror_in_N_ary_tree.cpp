// https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1

// Using unorderedmap of parent node and their children in a stack of tyoe <int,stack> and seeing if top of stack is equal to B[i]


class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        unordered_map<int,stack<int>> mp;
        for(int i = 0;i<2*e;i+=2)
        {
            mp[A[i]].push(A[i+1]);
        }
        
        for(int i = 0;i<2*e;i+=2)
        {
            if(mp[B[i]].top() != B[i+1])
            {
                return 0;
            }
            mp[B[i]].pop();
        }
        return 1;
    }
};
