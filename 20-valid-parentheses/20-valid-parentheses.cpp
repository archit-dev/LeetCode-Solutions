class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char &curr:s){
            if(curr=='(' || curr=='{' || curr=='['){
                st.push(curr);
            }else if(!st.empty()){
                if(curr==')' && st.top()!='(')  return false;
                else if(curr=='}' && st.top()!='{')  return false;
                else if(curr==']' && st.top()!='[') return false;
                else st.pop();
            }else{
                return false;
            }
        }
        return st.empty();
    }
};