class Solution {
public:
    
    int dp[1001][1001];
    
    int LCSHelper(string &word1 , string &word2 , int n, int m){
        if(n==0 || m == 0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(word1[n-1] == word2[m-1]){
            return dp[n][m] = 1+LCSHelper(word1,word2,n-1,m-1);
        }else{
            return dp[n][m] = max(LCSHelper(word1,word2,n,m-1),LCSHelper(word1,word2,n-1,m));
        }
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        memset(dp,-1,sizeof(dp));
        int lcsLength = LCSHelper(word1,word2,n,m);
        return (n-lcsLength)+ (m-lcsLength);
    }
};