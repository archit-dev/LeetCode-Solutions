class Solution {
public:
    int solve(vector<int>& nums,int curr,int n,vector<int>&dp)
    {
        if(curr==n) return 0;
        if(curr>n) return 1e9;
        if(dp[curr]!=-1) return dp[curr];
        int ans = 1e9;
        for(int i=1;i<=nums[curr];i++){
            int temp = solve(nums,curr+i,n,dp);
            ans = min(ans,temp);
        }
        return dp[curr] = ans+1;
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(nums,0,n-1,dp);
    }
};