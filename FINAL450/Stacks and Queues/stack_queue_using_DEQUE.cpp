// https://www.geeksforgeeks.org/implement-stack-queue-using-deque/

#include<iostream>
using namespace std;

class DLLNode
{
    public:
        int data;
        DLLNode* next = NULL;
        DLLNode* prev = NULL;
};


class Deque
{
    public:
        DLLNode* head;
        DLLNode* tail;
        int size = 0;

        Deque()
        {
            head = tail = NULL;
        }

        void insert_first(int a)
        {
            DLLNode* newNode = new DLLNode;
            newNode->data = a;
            if(head == NULL)
            {
                newNode->next = NULL;
                newNode->prev = NULL;
                head = newNode;
                tail = head;
            }
            else
            {
                newNode->next = head;
                head->prev = newNode;
                newNode->prev = NULL;
                head = newNode;
            }
        }

        void insert_end(int a)
        {
            DLLNode* newNode = new DLLNode;
            newNode->data = a;
            if(tail == NULL)
            {
                newNode->next = NULL;
                newNode->prev = NULL;
                head = newNode;
                tail = head;
            }
            else
            {
                newNode->prev = tail;
                tail->next = newNode;
                newNode->next = NULL;
                tail = newNode;
            }            
        }

        void remove_last()
        {
            if(tail->prev == NULL)
            {
                tail = NULL;
            }
            else
            {
                DLLNode* temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                temp->next = NULL;
                temp->prev = NULL;
            }
        }

        void remove_first()
        {
            if(head->next == NULL)
            {
                head = NULL;
            }
            else
            {
                DLLNode* temp = head;
                head = head->next;
                head->prev = NULL;
                temp->next = NULL;
                temp->prev = NULL;
            }
        }

        void display()
        {
            DLLNode* temp = head;
            while(temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }


};


class Stack
{
    public:
        Deque deque;
        int size = deque.size;

        void push(int x)
        {
            deque.insert_first(x);
        }

        void pop()
        {
            deque.remove_first();
        }
        void displayStack()
        {
            deque.display();
        }
};


class Queue
{
    public:    
        Deque deque;
        int size = deque.size;
        void enqueue(int x)
        {
            deque.insert_first(x);
        }
        void dequeue()
        {
            deque.remove_last();
        }
        void displayQueue()
        {
            deque.display();
        }

};

int main()
{
    // stack..
    cout << "STACK RUNNING .." << endl;
    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.displayStack();
    stk.pop();
    stk.displayStack();

    // Queue..
    cout << "QUEUE RUNNING .." << endl;
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.displayQueue();
    queue.dequeue();
    queue.displayQueue();
    return 0;
}
