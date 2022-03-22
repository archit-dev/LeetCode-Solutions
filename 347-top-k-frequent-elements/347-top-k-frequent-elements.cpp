class Solution {
public:
    #define pii pair<int,int>
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int x: nums) mpp[x]++;
        priority_queue<pii> pq;
        for(auto &it: mpp){
            pq.push({it.second,it.first});
        }
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};