class Solution {
public:
    int solve(vector<int>& nums,int n,int currDel,vector<vector<int>>&dp){
        if(n==0) return 0;
        if(dp[n][currDel]!=-1) return dp[n][currDel];
        int include = 0;
        int exclude = solve(nums,n-1,currDel,dp);
        while(n>0 && (nums[n-1]==currDel+1 || nums[n-1]==currDel-1)){
            n-=1;
        }
        if(n==0) return dp[n][currDel] =  0;
        include = solve(nums,n-1,nums[n-1],dp) + nums[n-1];
        return dp[n][currDel] = max(include,exclude);
    }
    
    int deleteAndEarn(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(10001,-1));
        sort(nums.begin(),nums.end());
        return solve(nums,nums.size(),5000,dp);
    }
};