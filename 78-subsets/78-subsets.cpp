class Solution {
public:
     vector<vector<int> > solve(vector<int>& nums,int idx){
        if(idx<0){
            vector<int>temp;
            vector<vector<int> > ans;
            ans.push_back(temp);
            return ans;
        }
         vector<vector<int> > rest = solve(nums,idx-1);
         vector<vector<int> > ans;
         for(int i=0;i<rest.size();i++){
             //exclude 
             ans.push_back(rest[i]);
             //include
             rest[i].push_back(nums[idx]);
             ans.push_back(rest[i]);
         }
         return ans;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        return solve(nums,nums.size()-1);
    }
};