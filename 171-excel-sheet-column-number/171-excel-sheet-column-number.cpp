class Solution {
public:
    int findVal(char x){
        return x-'A'+1;
    }
    
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = ans*26 + findVal(columnTitle[i]);
        }
        return ans;
    }
};