class Solution {
public:
    int longestSubarrayWithSumK(vector<int>& nums, int target){
        int length = INT_MIN,sum = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int remainingSum = sum-target;
            if(mp.find(remainingSum)!=mp.end()){
                length = max(length,i-mp[remainingSum]);
            }
            mp[sum] = i;
        }
        return length;
    }
    
    int minOperations(vector<int>& nums, int x) {
        //the idea is, some part of from left and some part from right
        //will sum upto x, hence it'll reduce the x to 0
        
        //conversely, we can say that some subarray in the middle has the sum
        //totalSum - x, 
        
        //since we need to minimize the number of steps to reduce x to zero,
        //we can maximize the length of this middle subarray with totalSum-x as the sum
        
        //therefore the problem boils down to, largest subarray with sum = k
        int sum = 0;
        for(int num:nums) sum+=num;
        int n = nums.size();
        if(sum==x) return n;
        int temp = longestSubarrayWithSumK(nums, sum-x);
        if(temp==INT_MIN) return -1;
        return n-temp;
            
    }
};