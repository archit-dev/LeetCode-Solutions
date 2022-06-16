class MyStack {
    private:
        queue<int>q1;
    public:
    MyStack() {
        
    }
    
    void push(int x) {
        //push the number in q1
        q1.push(x);
        //get the length of q1 except for current elemnet
        int len = q1.size()-1;
        //push all the other elements into the queue again
        while(len){
            int num = q1.front();
            q1.pop();
            q1.push(num);
            len--;
        }
    }
    
    int pop() {
        int num = q1.front();
        q1.pop();
        return num;
    }
    
    int top() {
        return q1.front();
    }
    
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