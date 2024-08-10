class MinStack {
    stack<long long int>s;
    long long int mini;
public:
    MinStack() {
        mini = 0;
    }
    
    void push(int val) {
        if(s.size()==0){
            mini = val;
            s.push(val*1LL-mini);
        }
        else{
            long long int rem  = val - mini;
            if(rem>=0)
            s.push(rem);
            else
            {s.push(rem);
            mini  = val;
            }
        }
    }
    
    void pop() {
        long long int x = s.top();
        s.pop();
        if(x<=0)
        mini = mini - x;
    }
    
    int top() {
        long long int x = s.top();
        if(x<=0)
        return mini;
        
        return x + mini;
    }
    
    int getMin() {
        return mini;
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