class Solution {
public:
    void combinationHelper(int idx,int k,int n,vector<int>& currentComb,
                          vector<vector<int>>& combinations)
    {
        if(k==0){
            combinations.push_back(currentComb);
            return;
        }
        if(n-idx+1<k){
            return; 
            //this is the case where even if we include all the 
            //remaining elements, we will not get size k, so return
        }
        if(idx>n) return;
        
        //include
        currentComb.push_back(idx);
        combinationHelper(idx+1,k-1,n,currentComb,combinations);
        
        //exclude
        currentComb.pop_back();
        combinationHelper(idx+1,k,n,currentComb,combinations);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int>currentComb;
        vector<vector<int>>combinations;
        combinationHelper(1,k,n,currentComb,combinations);
        return combinations;
    }
};