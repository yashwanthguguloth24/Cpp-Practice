// https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1#

// start from i = 0 and j = 1, (DONOT KEEP j>i)



bool findPair(int arr[], int size, int n){
    //code
    sort(arr,arr+size);
    int i = 0;
    int j = 1;
    while(j<size)
    {
        int x = arr[j]-arr[i];
        if(x == n)
        {
            return true;
        }
        else if(x > n)
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return false;
}
