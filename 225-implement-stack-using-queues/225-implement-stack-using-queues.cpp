class MyStack {
    private:
        queue<int>q1,q2;
    public:
    MyStack() {
        
    }
    
    void push(int x) {
        //push the number in q2
        q2.push(x);
        //insert numbers from q1 to q2 element by element
        while(!q1.empty()){
            int num = q1.front();
            q1.pop();
            q2.push(num);
        }
        //swap q1 and q2
        queue<int> temp = q2;
        q2 = q1;
        q1 = temp;
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