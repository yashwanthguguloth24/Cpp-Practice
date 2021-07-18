// https://www.geeksforgeeks.org/efficiently-implement-k-queues-single-array/

// using next array,front array , rear array to keep track of enqueue and dequeue operations

#include<iostream>
using namespace std;

class kQueues
{
    public:
        int N;
        int K;
        int* front;
        int* rear;
        int *arr;
        int *next;
        int free;
        kQueues(int k,int n)
        {
            N = n;
            K = k;
            front = new int[K];
            rear = new int[K];
            arr = new int[N];
            for(int i = 0;i<K;i++)
            {
                front[i] = -1;
            }
            for(int i = 0;i<N-1;i++)
            {
                next[i] = i+1;
            }
            next[N-1] = -1;
            free = 0;
        }

        bool isfull()
        {
            return free == -1;
        }

        bool isEmpty(int qn)
        {
            return front[qn] == -1;
        }

        void enqueue(int value,int qn)
        {
            if(isfull())
            {
                cout << "queue overflow" << endl;
            }

            int i = free;
            free = next[i];

            if(isEmpty(qn))
            {
                front[qn] = i;
            }
            else
            {
                next[rear[qn]] = i;
            }

            next[i] = -1;
            rear[qn] = i;
            arr[i] = value;
        }


        void dequeue(int qn)
        {
            if(isEmpty(qn))
            {
                cout << "queue underflow " << endl;
                return ;
            }
            int i = front[qn];
            int ans = arr[i];
            front[qn] = next[i];
            next[i] = free;
            free = i;
            cout << "dequeued element is : " << ans << endl;
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
    kQueues kq(2,8);
    kq.enqueue(22,0);
    kq.enqueue(23,0);
    kq.enqueue(24,0);
    kq.enqueue(90,1);
    kq.enqueue(91,1);
    kq.display();
    kq.dequeue(0);
    kq.dequeue(0);
    kq.dequeue(1);
    kq.display();

    return 0;
}
