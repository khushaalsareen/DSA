class MinStack {
    stack<long long  int>s;
    long long  int mini = 0;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.size()==0){
            mini = val;
            s.push(val - mini);
            return;
        }
       long long   int rem = val - mini;
        s.push(rem);
        if(rem<=0)
        mini = val;
    }
    
    void pop() {
      long long   int x = s.top();
        s.pop();
        if(x<=0)
        mini = mini-x;
    }
    
    int top() {
       long long  int rem = s.top();
       if(rem<=0)
       return mini;
        return rem + mini;
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