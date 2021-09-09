// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1


// using binary search by length of elements


class Solution{
    public:
    int kth(int arr1[],int arr2[],int l1,int r1,int l2,int r2,int n,int m,int k)
    {
        // base case
        if(l1 > r1){
            return arr2[l2+k-1];
        }
        if(l2 > r2){
            return arr1[l1+k-1];
        }
        
        int m1 = l1 + (r1-l1)/2;
        int m2 = l2 + (r2-l2)/2;
        int kc = (m1-l1+1)+(m2-l2+1);
        if(kc <= k)
        {
            if(arr1[m1]<arr2[m2])
            {
                return kth(arr1,arr2,m1+1,r1,l2,r2,n,m,k-(m1-l1+1));
            }
            else
            {
                return kth(arr1,arr2,l1,r1,m2+1,r2,n,m,k-(m2-l2+1));
            }
        }
        else
        {
            if(arr1[m1]<arr2[m2])
            {
                return kth(arr1,arr2,l1,r1,l2,m2-1,n,m,k);
            }
            else
            {
                return kth(arr1,arr2,l1,m1-1,l2,r2,n,m,k);
            }
        }
        
    }
    
    
    
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        return kth(arr1,arr2,0,n-1,0,m-1,n,m,k);
        
    }
};
