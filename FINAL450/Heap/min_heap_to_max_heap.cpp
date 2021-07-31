// https://www.geeksforgeeks.org/convert-min-heap-to-max-heap/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// we dont care about the input directly build max heap ...
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
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    Heap heap;
    cout << "Min heap :" << endl;
    heap.printHeap(arr,n);
    cout << "Max heap" << endl;
    heap.buildMaxHeap(arr,n);
    heap.printHeap(arr,n);
    return 0;
}
