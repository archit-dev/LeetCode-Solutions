class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0,high=0,len=INT_MAX;
        long long sum = 0;
        while(high<nums.size()){
            sum+=nums[high];
            bool enter = false;
            while(low<=high && sum>=target){
                sum-=nums[low];
                low++;
                enter = true;
            }
            if(enter && low!=0){
                low-=1;
                sum+=nums[low];
            }
            if(sum>=target){
                len = min(len,high-low+1);
            }
            high++;
        }
        return len==INT_MAX ? 0 : len;
    }
};