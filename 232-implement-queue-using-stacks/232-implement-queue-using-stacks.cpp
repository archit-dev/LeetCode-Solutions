class MyQueue {
public:
    stack<int> input,output;
    MyQueue() {
        
    }
    
    void push(int x) {
        //simply put the element in input stack
        input.push(x);
    }
    
    int pop() {
        //if both stacjs are empty it means queue is empty
        if(input.empty() && output.empty()) return -1;
        //if output is not empty, pop out its element
        if(!output.empty()){
            int num = output.top();
            output.pop();
            return num;
        }
        //otherwise, move all the elements from input to output and return top
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        int num = output.top();
        output.pop();
        return num;
    }
    
    int peek() {
        //if both stacjs are empty it means queue is empty
        if(input.empty() && output.empty()) return -1;
        //if output is not empty, pop out its element
        if(!output.empty()){
            int num = output.top();
            return num;
        }
        //otherwise, move all the elements from input to output and return top
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        int num = output.top();
        return num;
    }
    
    bool empty() {
        if(input.empty() && output.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */