class Solution {
public:
    bool isPalindrome(string s) {
        string toCmp = "";
        for(char x:s){
            if(isalnum(x)){
               toCmp+= (char)tolower(x); 
            }
        }
        string cpy = toCmp;
        reverse(cpy.begin(),cpy.end());
        return toCmp==cpy;
    }
};