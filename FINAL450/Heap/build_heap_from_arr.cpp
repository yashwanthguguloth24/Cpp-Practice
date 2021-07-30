// https://www.geeksforgeeks.org/building-heap-from-array/

//using standard heapify operation from last parent node

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class arrayToMinHeap
{
    public:
        void heapify(int arr[],int n,int i)
        {
            int smallest = i;
            int l = 2*i+1; // left child
            int r = 2*i+2;

            if(l<n && arr[l]<arr[smallest])
            {
                smallest = l;
            } 

            if(r<n && arr[r] < arr[smallest])
            {
                smallest = r;
            }

            if(smallest != i)
            {
                swap(arr[i],arr[smallest]);
                heapify(arr,n,smallest);
            }                      
        }

        void buildHeap(int arr[],int n)
        {
            int start_ind = (n/2)-1;
            while(start_ind >= 0)
            {
                heapify(arr,n,start_ind);
                start_ind--;
            }

        }

        void printHeap(int arr[],int n)
        {
            for(int i = 0;i<n;i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};


int main()
{
    int arr[] = {1,3,5,4,6,13,10,9,8,15,17};
    int n = sizeof(arr) / sizeof(arr[0]);
    arrayToMinHeap s;
    s.buildHeap(arr,n);
    s.printHeap(arr,n);
    return 0;
}
