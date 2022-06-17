class MinStack {
public:
    stack<long long> st;
    long long minVal;
    MinStack() {
        minVal = LLONG_MAX;
    }
    
    void push(int val) {
        long long val_ = val;
        if(st.empty()){
            minVal = val_;
            st.push(val_);
            return;
        }
        //if not empty, check with min value
        //if it is greater, simply insert it
        if(val_>=minVal){
            st.push(val_);
        }else{
            //if it is not greater, insert a flag value
            st.push(2*val_-minVal);
            minVal = val_;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        //check the topmost value with min
        if(st.top()>=minVal) st.pop();
        //if not greater, modify the min val
        else{
            minVal = 2*minVal - st.top();
            st.pop();
        }
    }
    
    int top() {
        //similar to pop, if topmost value is greater, return top
        //otherwise, it'll be a flag and find out the accurate value 
        //using the formula
        if(st.empty()) return -1;
        if(st.top()>=minVal) return st.top();
        return minVal;
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return minVal;
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