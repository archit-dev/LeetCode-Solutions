class Solution {
public:
    int subarraysWithAtMostKDistinct(vector<int>& nums,int k){
        unordered_map<int,int> mp;
        int count = 0 , low = 0 , high = 0;
        while(high<nums.size()){
            int currNum = nums[high];
            mp[currNum]+=1;
            while(low<=high && mp.size()>k){
                mp[nums[low]]-=1;
                if(mp[nums[low]]==0) mp.erase(nums[low]);
                low++;
            }
            count+=high-low+1;
            high++;
        }
        return count;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtMostKDistinct(nums,k) - subarraysWithAtMostKDistinct(nums,k-1);
    }
};