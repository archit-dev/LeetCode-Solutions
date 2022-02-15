class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = solve(n-1,dp)+solve(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            int ans = dp[i-1];
            if(i-2>=0) ans += dp[i-2];
            dp[i] = ans;
        }
        return dp[n];
    }
};