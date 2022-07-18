class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int x:nums) mp[x]+=1;
        vector<vector<int>>temp(n+1);
        for(auto it:mp){
            int num = it.first;
            int cnt = it.second;
            temp[cnt].push_back(num);
        }
        vector<int> ans;
        int ptr = n;
        while(ptr>=0 && ans.size()!=k){
            for(int x:temp[ptr]){
                ans.push_back(x);
                if(ans.size()==k) break;
            }
            ptr--;
        }
        return ans;
    }
};