// https://leetcode.com/problems/design-circular-queue/

// References : https://www.youtube.com/watch?v=dn01XST9-bI

// Using array and using front and rear pointers accordingly for the given operation

class MyCircularQueue {
public:
    /*
    NOTATION: 
    [_,_,_,_,_]
  front      rear
    */
    
    
    int *circQueue;
    int rear;
    int front;
    int K;
    MyCircularQueue(int k) {
        rear = -1;
        front = -1;
        K = k;
        circQueue = new int[K]; 
    }
    
    bool enQueue(int value) {
        if((rear+1)%K == front)
        {
            return false;
        }
        
        
        if(rear == -1 && front == -1)
        {
            rear = front = 0;
            circQueue[rear] = value;
            return true;
        }
        else
        {
            rear = (rear+1)%K;
            circQueue[rear] = value;
            return true;             
        }
        
    }
    
    bool deQueue() {
        if(rear == -1 && front == -1)
        {
            return false;
        }
        else if(rear == front)
        {
            rear = front = -1;
            return true;
        }
        else
        {
            front = (front+1)%K;
            return true;
        }
    }
    
    int Front() {
        if(front == -1)
        {
            return -1;
        }
        else
        {
            return circQueue[front];
        }
    }
    
    int Rear() {
        if(rear == -1)
        {
            return -1;
        }
        else
        {
            return circQueue[rear];
        }
    }
    
    bool isEmpty() {
        if(rear == -1 && front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool isFull() {
        if((rear+1)%K == front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
