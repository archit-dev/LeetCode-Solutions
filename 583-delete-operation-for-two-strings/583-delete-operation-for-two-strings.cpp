class Solution {
public:
    int LCS(string a,string b,int ptr1,int ptr2,vector<vector<int>>&dp){
        if(ptr1==a.size() || ptr2==b.size()) return 0;
        if(dp[ptr1][ptr2]!=-1) return dp[ptr1][ptr2];
        if(a[ptr1]==b[ptr2]){
            return dp[ptr1][ptr2] = 1+LCS(a,b,ptr1+1,ptr2+1,dp);
        }
        return dp[ptr1][ptr2] = max(LCS(a,b,ptr1+1,ptr2,dp),LCS(a,b,ptr1,ptr2+1,dp));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int> >dp(word1.size(),vector<int>(word2.size(),-1));
        int lcs = LCS(word1,word2,0,0,dp);
        return word1.size()+word2.size()-2*lcs;
    }
};