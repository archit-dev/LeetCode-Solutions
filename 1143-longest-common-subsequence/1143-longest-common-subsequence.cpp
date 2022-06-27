class Solution {
public:
    int helper(string &a,int alen,string &b,int blen,vector<vector<int>>&dp){
        if(alen<0 || blen<0) return 0;
        
        if(dp[alen][blen]!=-1) return dp[alen][blen];
        
        if(a[alen]==b[blen]) return dp[alen][blen] = 1+helper(a,alen-1,b,blen-1,dp);
        
        int includeA = helper(a,alen,b,blen-1,dp);
        int includeB = helper(a,alen-1,b,blen,dp);
        return dp[alen][blen] = max(includeA,includeB);
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size() , n2 = text2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return helper(text1,n1-1,text2,n2-1,dp);
    }
};