class Solution {
public:
    bool isSubsequence(string s, string t) {
        int low1 = 0, low2 = 0;
        int sSize = s.size() , tSize = t.size();
        while(low1<sSize && low2<tSize){
            if(s[low1]==t[low2]){
                low1++;
            }
            low2++;
        }
        return low1==sSize;
    }
};