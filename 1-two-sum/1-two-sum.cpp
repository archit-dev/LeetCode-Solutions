class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            int rem = target-x;
            if(mp.find(rem)!=mp.end() ){
                // cout<<rem<<"->"<<mp[rem]<<" "<<x <<"-->"<<mp[x]<<"\n";
                ans.push_back(mp[rem]);
                ans.push_back(i);
                break;
            } else{
                mp[x] = i;
            }
        }
        return ans;
    }
};

