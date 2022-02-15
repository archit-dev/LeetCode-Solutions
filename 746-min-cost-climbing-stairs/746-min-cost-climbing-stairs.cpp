class Solution {
public:
    int solve(vector<int>& cost,int curr,int n,vector<int>&dp){
        if(curr==n) return 0;
        if(curr>n) return 1e9;
        if(dp[curr+1]!=-1) return dp[curr+1];
         
        int currCost = curr==-1 ? 0 : cost[curr];
        int oneStep = solve(cost,curr+1,n,dp);
        int twoSteps = solve(cost,curr+2,n,dp);
        return dp[curr+1] = min(oneStep,twoSteps) + currCost;
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);
        return solve(cost,-1,n,dp);

    }
};