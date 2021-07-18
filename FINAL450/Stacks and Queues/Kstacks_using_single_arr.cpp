// https://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/

// use next array,top array,free pointers to update push and pop operations

#include<iostream>
using namespace std;


class KStacks
{
    public:
        int K;
        int *top;
        int *next;
        int *arr;
        int free;
        int N;
        KStacks(int k,int n)
        {
            K = k;
            N = n;
            arr = new int[N];
            next = new int[N];
            top = new int[K];
            free = 0;
            for(int i = 0;i<N-1;i++)
            {
                next[i] = i+1;
                arr[i] = -1;
            }
            next[N-1] = -1;
            arr[N-1] = -1;

            for(int i =0;i<K;i++)
            {
                top[i] = -1;
            }
        }

        bool isfull()
        {
            return free == -1;
        }

        bool isEmpty(int sn)
        {
            return top[sn] == -1;
        }

        void push(int value,int sn)
        {
            if(isfull())
            {
                cout << "stack overflow" << endl;
                return;
            }
            int i = free;
            free = next[i];

            next[i] = top[sn];
            top[sn] = i;

            arr[i] = value;
        }

        void pop(int sn)
        {
            if(isEmpty(sn))
            {
                cout << "stack underflow" << endl;
                return ;
            }
            int i = top[sn];
            int ans = arr[i];
            top[sn] = next[i];
            next[i] = free;
            free = i;
            cout << "popped element is : " << ans << endl;
        }

        void display()
        {
            for(int i = 0;i<N;i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};




int main()
{
    KStacks kstks(5,10);
    kstks.push(5,0);
    kstks.display();
    kstks.push(3,1);
    kstks.display();
    kstks.push(7,2);
    kstks.display();
    kstks.push(90,3);
    kstks.display();
    kstks.push(88,4);
    kstks.display();
    kstks.push(66,4);
    kstks.display();
    kstks.pop(0);
    kstks.display();
    kstks.pop(1);
    kstks.display();
    kstks.pop(2);
    kstks.display();
    kstks.pop(3);
    kstks.display();
    kstks.pop(4);
    kstks.display();
    kstks.pop(4);
    kstks.display();
    cout << kstks.isEmpty(3) << endl;
    return 0;
}
