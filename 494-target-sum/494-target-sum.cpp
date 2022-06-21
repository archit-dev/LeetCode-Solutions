class Solution {
public:
    int solve(vector<int>& nums, int sum ,int target,int idx,
              map<pair<int,int>,int> &dp){
        if(idx==nums.size()){
            return sum==target;
        }
        if(dp.find({sum,idx})!=dp.end()) return dp[{sum,idx}];
        int include = solve(nums,sum+nums[idx],target,idx+1,dp);
        int exclude = solve(nums,sum-nums[idx],target,idx+1,dp);
        return dp[{sum,idx}] = include+exclude;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>,int>mp;
        return solve(nums,0,target,0,mp);
    }
};