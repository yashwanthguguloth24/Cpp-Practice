// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1


//*******************************My sol********************************************
class Solution 
{
    public:
    
    int NumStudents(int A[],int N,int max_val)
    {
        int cnt = 1;
        int curr_sum = 0;
        for(int i = 0;i<N;i++)
        {
            if(A[i] > max_val)
            {
                return INT_MAX;
            }
            if(curr_sum + A[i] > max_val)
            {
                cnt++;
                curr_sum = A[i];
            }
            else
            {
                curr_sum += A[i];
            }
        }
        // cout << "bs " << max_val << " " << cnt << endl;
        return cnt;
    }
    
    
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M > N)
        {
            return -1;
        }
        
        if(M == N)
        {
            int ans = 0;
            for(int i = 0;i<N;i++)
            {
                ans = max(ans,A[i]);
            }
            return ans;
        }
        
        int sm = 0;
        for(int i = 0;i<N;i++) 
        {
            sm += A[i];
        }
        
        int l = 0;
        int r = sm;
        int ans = -1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            // cout << "main " << mid << endl;
            int k = NumStudents(A,N,mid);
            if(k == M)
            {
                ans = mid;
                r = mid-1;
            }
            else if(k > M)
            {
                l = mid+1;
            }
            else
            {
                ans = mid;
                r = mid-1;
            }
        }
        return ans;
    }
};



///*****************GFG****************************
#include<bits/stdc++.h>
using namespace std;
 
// Utility function to check if current minimum value
// is feasible or not.
bool isPossible(int arr[], int n, int m, int curr_min)
{
    int studentsRequired = 1;
    int curr_sum = 0;
 
    // iterate over all books
    for (int i = 0; i < n; i++)
    {
        // check if current number of pages are greater
        // than curr_min that means we will get the result
        // after mid no. of pages
        if (arr[i] > curr_min)
            return false;
 
        // count how many students are required
        // to distribute curr_min pages
        if (curr_sum + arr[i] > curr_min)
        {
            // increment student count
            studentsRequired++;
 
            // update curr_sum
            curr_sum = arr[i];
 
            // if students required becomes greater
            // than given no. of students,return false
            if (studentsRequired > m)
                return false;
        }
 
        // else update curr_sum
        else
            curr_sum += arr[i];
    }
    return true;
}
 
// function to find minimum pages
int findPages(int arr[], int n, int m)
{
    long long sum = 0;
 
    // return -1 if no. of books is less than
    // no. of students
    if (n < m)
        return -1;
 
    // Count total number of pages
    for (int i = 0; i < n; i++)
        sum += arr[i];
 
    // initialize start as 0 pages and end as
    // total pages
    int start = 0, end = sum;
    int result = INT_MAX;
 
    // traverse until start <= end
    while (start <= end)
    {
        // check if it is possible to distribute
        // books by using mid as current minimum
        int mid = (start + end) / 2;
        if (isPossible(arr, n, m, mid))
        {
            // update result to current distribution
              // as it's the best we have found till now.
              result = mid;
 
            // as we are finding minimum and books
            // are sorted so reduce end = mid -1
            // that means
            end = mid - 1;
        }
 
        else
            // if not possible means pages should be
            // increased so update start = mid + 1
            start = mid + 1;
    }
 
    // at-last return minimum no. of  pages
    return result;
}
 
// Drivers code
int main()
{
    //Number of pages in books
    int arr[] = {12, 34, 67, 90};
    int n = sizeof arr / sizeof arr[0];
    int m = 2; //No. of students
 
    cout << "Minimum number of pages = "
         << findPages(arr, n, m) << endl;
    return 0;
}
