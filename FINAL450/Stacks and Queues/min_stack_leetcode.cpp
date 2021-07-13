// https://leetcode.com/problems/min-stack/

// Using 2 stack approach.

class MinStack {
public:
    /** initialize your data structure here. */
    // long long int min_val;
    vector<int>stk;
    vector<int> min_stk;
    MinStack() {
        // min_val = INT_MAX;
    }
    
    void push(int val) {
        if(stk.size() == 0)
        {
            stk.push_back(val);
            min_stk.push_back(val);
        }
        else
        {
            if(val > min_stk[min_stk.size()-1])
            {
                stk.push_back(val);
                min_stk.push_back(min_stk[min_stk.size()-1]);
            }
            else
            {
                stk.push_back(val);
                min_stk.push_back(val);
            }
            // if(val>min_val)
            // {
            //     stk.push_back(val);
            // }
            // else
            // {
            //     long long int y = (long long int )2*val-min_val;
            //     stk.push_back(y);
            //     min_val = val;
            // }
        }
    }
    
    void pop() {
        if(stk.size() == 0)
        {
            return ;
        }
        else
        {   
            stk.pop_back();
            min_stk.pop_back();
            // long long int y1 = stk[stk.size()-1];
            // if(y1 > min_val)
            // {
            //     stk.pop_back();
            // }
            // else
            // {
            //     min_val = (long long int) 2*min_val - y1;
            //     stk.pop_back();
            // }
        }
    }
    
    int top() {
        if(stk.size() == 0)
        {
            return -1;
        }
        else
        {
            return stk[stk.size()-1];
            // long long int y1 = stk[stk.size()-1];
            // if(y1 > min_val)
            // {
            //     return y1;
            // }
            // else
            // {
            //     min_val = 2*min_val - y1;
            //     long long int actual = (y1+min_val)/2;
            //     return actual;
            // }
        }
    }
    
    int getMin() {
        // return (int)min_val;
        return min_stk[min_stk.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
