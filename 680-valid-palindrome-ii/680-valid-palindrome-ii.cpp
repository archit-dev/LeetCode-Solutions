class Solution {
public:
    bool palindrome(string &s){
        int low = 0, high = s.size()-1;
        while(low<high){
            if(s[low]==s[high]){
                low++;
                high--;
            }else{
                return false;
            }
        }
        return true;
    }
    
    bool isPalin(string &s,int low,int high,int cnt){
        if(low>high) return true;
        if(s[low]==s[high]) return isPalin(s,low+1,high-1,cnt);
        if(cnt==1) return false;
        return isPalin(s,low+1,high,1) || isPalin(s,low,high-1,1);
    }
    
    bool validPalindrome(string s) {
        if(palindrome(s))return true;
        else return isPalin(s,0,s.size()-1,0);
    }
};