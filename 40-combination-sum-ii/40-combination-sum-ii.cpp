class Solution {
public:
    void helper(vector<vector<int>>&ans,vector<int>& cand,int tgt,vector<int>& curr,int idx){
        if(tgt<0) return;
        if(tgt==0){
            ans.push_back(curr);
            return;
        }
        if(idx==cand.size()) return;
        //include 
        curr.push_back(cand[idx]);
        helper(ans,cand,tgt-cand[idx],curr,idx+1);
        //exlcude
        curr.pop_back();
        int currelement = cand[idx];
        while(idx<cand.size() && currelement==cand[idx]) idx++;
        helper(ans,cand,tgt,curr,idx);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        sort(candidates.begin(),candidates.end());
        helper(ans,candidates,target,curr,0);
        return ans;
    }
};