#include <iostream>

using namespace std;

int* CumSum(int arr[],int N)
{
    int cumsum = 0;
    for(int i = 0;i<N;i++)
    {
        cumsum += arr[i];
        arr[i] = cumsum;
    }
    return arr;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int* p;
    //cout << &CumSum(arr,5) << endl;
    p = CumSum(arr,5);
    for(int i = 0;i<5;i++)
    {
        cout << *(p+i) << endl;
    }
}
