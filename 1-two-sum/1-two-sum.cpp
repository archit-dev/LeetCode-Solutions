class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans (2,-1);
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int current = nums[i];
            int other = target - current;
            if(mp.find(other)!=mp.end()){
                ans[0] = i;
                ans[1] = mp[target - nums[i]];
                return ans;
            }else{
                mp[current] = i;
            }
        }
        return ans;
    }
};

