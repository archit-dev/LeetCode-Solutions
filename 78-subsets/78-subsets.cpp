class Solution {
public:
    vector<vector<int> > solve(vector<int>&nums,int idx){
        if(idx<0){
            vector<vector<int> > tempAns;
            vector<int>temp;
            tempAns.push_back(temp);
            return tempAns;
        }
        vector<vector<int> > remaining = solve(nums,idx-1);
        vector<vector<int> > newVec;
        for(int i=0;i<remaining.size();i++){
            //exclude
            newVec.push_back(remaining[i]);
            //include
            remaining[i].push_back(nums[idx]);
            newVec.push_back(remaining[i]);
        }
        return newVec;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        return solve(nums,nums.size()-1);
    }
};