class Solution {
public:
    bool isPalindrome(string s) {
        int low = 0, high = s.size()-1;
        while(low<=high){
            while(low<=high && !isalnum(s[low])) low++;
            while(high>=low && !isalnum(s[high])) high--;
            
            if( (char)tolower(s[low]) != (char)tolower(s[high]) )
            {
                if(low<=high) return false;
            }
            low+=1;
            high-=1;
        }
        return true;
    }
};