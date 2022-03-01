class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ansSoFar = 0;
        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++){
            ansSoFar += nums[i];
            ans = max(ans,ansSoFar);
            ansSoFar = max(0,ansSoFar);
        }
        return ans;
    }
    
};