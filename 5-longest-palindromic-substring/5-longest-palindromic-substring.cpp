class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int bestLen = 0;
        int n = s.size();
        //for odd length palindrome
        for(int i=0;i<n;i++){
            int left = i, right = i;
            while(left>=0 && right<n && s[left]==s[right]){
                if(right-left+1 > bestLen){
                    bestLen = right-left+1;
                    ans = s.substr(left,right-left+1);
                }
                left--;
                right++;
            }
            
        }
        //for even length palindrome
        for(int i=0;i<n-1;i++){
            int left = i, right = i+1;
            while(left>=0 && right<n && s[left]==s[right]){
                if(right-left+1> bestLen){
                    bestLen = right-left+1;
                    ans = s.substr(left,right-left+1);
                }
                left--;
                right++;
            }
        }
        return ans;
    }
};