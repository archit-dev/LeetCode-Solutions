class Solution {
public:
    bool solve(vector<int>&nums,int current,int n,vector<int>&dp){ 
        if(current==n) return true;
        if(current>n) return false;
        if(dp[current]!=-1) return dp[current];
        bool ans = false;
        for(int i=1;i<=nums[current];i++){
            ans = solve(nums,current+i,n,dp);
            if(ans==true) break;
        }
        return dp[current] = ans;
    }
    
    bool canJump(vector<int>& nums) { 
        int n=nums.size()-1;
        vector<int>dp(n+1,-1);
        return solve(nums,0,n,dp);
    }
};