// https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1#

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        set<int, greater<int>> union_set;
        for(int i = 0; i<n;i++)
        {
            union_set.insert(a[i]);
        }
        for(int j = 0; j<m;j++)
        {
            union_set.insert(b[j]);
        }
        return union_set.size();
    }
};
