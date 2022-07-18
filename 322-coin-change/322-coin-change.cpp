class Solution {
public:
    int dp[100000][20];
    
    int helper(vector<int>& coins,int amt,int ptr){
        if(ptr==coins.size()){
            if(amt==0) return 0;
            return 1e9;
        }
        if(amt==0) return 0;
        if(amt<0) return 1e9;
        if(dp[amt][ptr]!=-1) return dp[amt][ptr];
        int ans = -1;
        if(coins[ptr]<=amt){
            int take = 1 + helper(coins,amt-coins[ptr],ptr);
            int dontTake = helper(coins,amt,ptr+1);
            ans = min(take,dontTake);
        }
        else{
            ans = helper(coins,amt,ptr+1);
        }
        return dp[amt][ptr] = ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int ptr = 0;
        memset(dp,-1,sizeof dp);
        int ans = helper(coins,amount,ptr);
        return ans!=1e9 ? ans : -1;
    }
};