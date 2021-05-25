// https://practice.geeksforgeeks.org/problems/three-way-partitioning/1#

// Approach:

/*
           --> i
   -   -   -  -  -  -  -  -  -  -  -  - 
       a < |                    | > b
           |                    |
          left                 right

Iterate such that left and right are boundaries for a and b.

*/


void threeWayPartition(int arr[], int n, int a, int b)
{
      int left = 0;
      int right = n-1;
      int i = 0;
      while(i<=right)
      {
          if(arr[i]<a)
          {
              int temp;
              temp = arr[left];
              arr[left] = arr[i];
              arr[i] = temp;
              //swap(arr[i],arr[left]);
              left++;
              i++;
          }
          else if(arr[i]>b)
          {
              int temp;
              temp = arr[right];
              arr[right] = arr[i];
              arr[i] = temp;
              //swap(arr[i],arr[right]);
              right--;
          }
          else
          {
              i++;
          }
      }
}
