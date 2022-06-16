class Solution {
    private:
    bool open(char x){
        return x=='(' || x=='{' || x=='[';
    }
    
    bool match(char a,char b){
        if(a=='(') return b==')';
        if(a=='{') return b=='}';
        if(a=='[') return b==']';
        return false;
    }
    public:
    bool isValid(string s) {
        stack<char>st;
        for(char x:s){
            if(open(x)){
                //if it is an opening brackett
                st.push(x);
            }else{
                //if it is a closing bracket
                //1. if the stack is empty, return false
                if(st.empty()) return false;
                //2. if the curr bracket and top of stack dont match return false
                if(!match(st.top(),x)) return false;
                //3. if they match , pop out the top of stacl
                else st.pop();
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};