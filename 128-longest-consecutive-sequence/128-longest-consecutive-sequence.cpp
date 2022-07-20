class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int ans = 0;
        for(int &x:nums)st.insert(x);
        
        for(int i=0;i<nums.size();i++){
            int currEle = nums[i];
            if(st.find(currEle-1)!=st.end()){
                continue;
            }
            int currLen = 0;
            while(st.find(currEle)!=st.end()){
                currLen+=1;
                currEle+=1;
                ans = max(ans,currLen);
            }
            ans = max(ans,currLen);   
        }
        return ans;
    }
};