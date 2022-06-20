class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int high = 0,ans=0;
        long long sum =0 ;
        while(high<nums.size()){
            sum+=nums[high];
            int rem = (sum%k + k)%k;
            if(mp.find(rem)!=mp.end()){
                ans+=mp[rem];
            }
            mp[rem]+=1;
            high++;
        }
        return ans;
    }
};