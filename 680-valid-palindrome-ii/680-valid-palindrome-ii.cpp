class Solution {
public:
    bool isPalin(string &s,int low,int high,int cnt){
        if(low>=high) return true;
        if(s[low]==s[high]) return isPalin(s,low+1,high-1,cnt);
        if(cnt==1) return false;
        return isPalin(s,low+1,high,1) || isPalin(s,low,high-1,1);
    }
    
    bool validPalindrome(string s) {
        return isPalin(s,0,s.size()-1,0);
        
    }
};

// a b c c b a e