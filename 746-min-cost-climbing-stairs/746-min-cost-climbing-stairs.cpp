class Solution {
public:
    int dp[10001];
    int solve(int currIndex,vector<int>& cost){
        if(currIndex==cost.size()){
            return 0;
        }
        if(currIndex>cost.size()){
            return 1e9;
        }
        if(dp[currIndex]!=-1) return dp[currIndex];
        int one = cost[currIndex]+solve(currIndex+1,cost);
        int two = cost[currIndex]+solve(currIndex+2,cost);
        return dp[currIndex] = min(one,two);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof dp);
        int zero = solve(0,cost);
        int one = solve(1,cost);
        return min(one,zero);
    }
};