class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //the main idea is that, the maximum profit at
        //any point can be prices[i] - minimumSoFar
        int ans = 0;
        int n = prices.size();
        int minSoFar = INT_MAX;
        for(int i=0;i<n;i++){
            minSoFar = min(minSoFar,prices[i]);
            if(prices[i]-minSoFar > ans){
                ans = prices[i] - minSoFar;
            }
        }
        return ans;
    }
};