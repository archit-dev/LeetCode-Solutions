class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long sum = (n*(n+1))/2;
        long long sum_ = 0;
        for(auto &it:nums) sum_+=it;
        return abs(sum-sum_);
    }
};