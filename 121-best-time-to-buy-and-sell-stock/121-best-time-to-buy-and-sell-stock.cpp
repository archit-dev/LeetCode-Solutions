class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //2 pointers => left = buy, right = sell
        //buy low and sell high
        int left = 0 , right = 1;
        int netProfit = 0,n = prices.size();
        while(right<n){
            int currProfit = prices[right] - prices[left];
            netProfit = max(currProfit,netProfit);
            if(prices[left] > prices[right]){
                left = right;
            }
            right+=1;
        }
        return netProfit;
    }
};