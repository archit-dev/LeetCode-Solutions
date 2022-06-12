class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ptr1 = 0, ptr2 =0;
        int ans = 0, tempAns = 0;
        unordered_map<int,int> mp;
        while(ptr2<nums.size()){
            if(mp.find(nums[ptr2])!=mp.end()){
                int idx = mp[nums[ptr2]];
                while(ptr1<=idx){
                    tempAns-=nums[ptr1];
                    mp.erase(nums[ptr1]);
                    ptr1++;
                }
            }
            mp[nums[ptr2]]=ptr2;
            tempAns+=nums[ptr2];
            ans= max(ans,tempAns);
            ptr2++;
        }
        return ans;
    }
};