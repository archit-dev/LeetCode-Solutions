class Solution {
public:
    int LISHelper(vector<int>& nums,int idx,int prevIndex,
                 vector<vector<int>> &dp)
    {
        if(idx==nums.size()) return 0;
        if(dp[idx][prevIndex+1]!=-1) return dp[idx][prevIndex+1];
        //exclude
        int exclude = LISHelper(nums,idx+1,prevIndex,dp);
        
        //include 
        int include = INT_MIN;
        if(prevIndex==-1 || nums[idx]>nums[prevIndex]){
            include = LISHelper(nums,idx+1,idx,dp) + 1;
        }
        
        return dp[idx][prevIndex+1] = max(include,exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return LISHelper(nums,0,-1,dp);
    }
};