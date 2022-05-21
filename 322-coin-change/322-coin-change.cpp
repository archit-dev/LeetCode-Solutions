class Solution {
public:
    int dp[13][10001];
    int solve(vector<int>& coins,int amount, int currentIndex,int numberOfCoins){
        if(currentIndex<0) return 1e9;
        if(amount<0) return 1e9;
        if(amount==0) return 0;
        if(dp[currentIndex][amount]!=-1) return dp[currentIndex][amount];
        int include = solve(coins,
                            amount-coins[currentIndex],
                            currentIndex,
                            numberOfCoins+1)+1;
        int exclude = solve(coins,
                            amount,
                            currentIndex-1,
                            numberOfCoins);
        return dp[currentIndex][amount] = min(include,exclude);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp,-1,sizeof dp);
        int ans = solve(coins,amount,n-1,0);
        return ans!=1e9 ? ans:-1;
    }
};