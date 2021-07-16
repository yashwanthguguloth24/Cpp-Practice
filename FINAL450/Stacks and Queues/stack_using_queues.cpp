// https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1#

// https://leetcode.com/problems/implement-stack-using-queues/

//APPROACH 1 ********USING 2 STACKS**********************

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q1.size() == 0)
        {
            return -1;
        }
        int temp;
        while(q1.size()>1)
        {
            temp = q1.front();
            q1.pop();
            q2.push(temp);
        }
        int ans = q1.front();
        q1.pop();
        swap(q1,q2);
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        if(q1.size() == 0)
        {
            return -1;
        }
        int temp;
        while(q1.size()>1)
        {
            temp = q1.front();
            q1.pop();
            q2.push(temp);
        }
        int ans = q1.front();
        q1.pop();
        q2.push(ans);
        swap(q1,q2);
        return ans;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */



//APPROACH 2:*******USING 1 STACK*********************

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q1.size() == 0)
        {
            return -1;
        }
        int temp;
        int t = q1.size()-1;
        while(t>0)
        {
            temp = q1.front();
            q1.pop();
            q1.push(temp);
            t--;
        }
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        if(q1.size() == 0)
        {
            return -1;
        }
        int temp;
        int t = q1.size()-1;
        while(t>0)
        {
            temp = q1.front();
            q1.pop();
            q1.push(temp);
            t--;
        }
        int ans = q1.front();
        q1.pop();
        q1.push(ans);
        return ans;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


