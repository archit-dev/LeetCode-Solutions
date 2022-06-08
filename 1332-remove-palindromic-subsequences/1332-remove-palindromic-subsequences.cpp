class Solution {
public:
    bool isPalin(string s){
        int low = 0, high = s.size()-1;
        while(low<high){
            if(s[low]!=s[high]) return false;
            low++;
            high--;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        int ans = 1;
        if(!isPalin(s)) ans++;
        return ans;
    }
};