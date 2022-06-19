class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN , currSum = 0;
        for(int i=0;i<nums.size();i++){
            currSum += nums[i];
            maxSum = max(currSum,maxSum);
            currSum = max(0,currSum);
        }
        return maxSum;
    }
};