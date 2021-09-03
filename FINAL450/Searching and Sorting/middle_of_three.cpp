// https://practice.geeksforgeeks.org/problems/middle-of-three2926/1#

class Solution{
  public:
    int middle(int A, int B, int C){
        //code here//Position this line where user code will be pasted.
        int mn = min(A,min(B,C));
        int mx = max(A,max(B,C));
        return (mn^mx^A^B^C);
    }
};
