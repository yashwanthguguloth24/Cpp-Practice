// https://www.geeksforgeeks.org/heap-sort/

// Build Max heap, then swap the top element(largest) with last element and decrease length

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Heap
{
    public:
        void heapify(int arr[],int n,int i)
        {
            int largest = i;
            int l = 2*i+1; // left child
            int r = 2*i+2;

            if(l<n && arr[l]>arr[largest])
            {
                largest = l;
            } 

            if(r<n && arr[r] > arr[largest])
            {
                largest = r;
            }

            if(largest != i)
            {
                swap(arr[i],arr[largest]);
                heapify(arr,n,largest);
            }                      
        }

        void buildMaxHeap(int arr[],int n)
        {
            int start_ind = (n/2)-1;
            while(start_ind >= 0)
            {
                heapify(arr,n,start_ind);
                start_ind--;
            }

        }

        void HeapSort(int arr[],int n)
        {
            buildMaxHeap(arr,n);

            for(int i = n-1;i>=0;i--)
            {
                swap(arr[0],arr[i]);
                heapify(arr,i,0);
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
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    Heap heap;
    heap.HeapSort(arr,n);
    heap.printHeap(arr,n);
    return 0;
}
