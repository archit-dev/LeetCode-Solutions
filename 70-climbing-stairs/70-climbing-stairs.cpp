class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = solve(n-1,dp)+solve(n-2,dp);
    }
    int climbStairs(int n) { 
        int step1 = 1;
        int step2 = 0;
        for(int i=1;i<=n;i++){
            int ans = step1;
            if(i-2>=0) ans += step2;
            step2 = step1;
            step1 = ans;
        }
        return step1;
    }
};