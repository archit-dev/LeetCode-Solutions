class Solution {
public:
    bool solve(vector<int>&nums,int n,int sum,vector<vector<int>>&dp){
        if(sum<0) return false;
        if(n==0) return sum==0;
        if(dp[n][sum]!=-1) return dp[n][sum];
        return dp[n][sum] = solve(nums,n-1,sum,dp) || solve(nums,n-1,sum-nums[n-1],dp);
    }
    
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int &x:nums){
            sum+=x;
        }
        if(sum%2!=0) return false;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(nums,n,sum/2,dp);
    }
    
};