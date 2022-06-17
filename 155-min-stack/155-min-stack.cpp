class MinStack {
public:
    stack<int>std,mini;
    MinStack() {
        
    }
    
    void push(int val) {
        if(std.empty()){
            std.push(val);
            mini.push(val);
            return;
        }
        std.push(val);
        mini.push(min(val,mini.top()));
    }
    
    void pop() {
        std.pop();
        mini.pop();
    }
    
    int top() {
        return std.top();
    }
    
    int getMin() {
        return mini.top();
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