class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int num:nums) st.insert(num);
        int len = 0;
        for(int num:nums){
            if(st.find(num-1)!=st.end()){
                continue;
            }else{
                int currLen = 0;
                int tempNum = num;
                while(st.find(tempNum)!=st.end()){
                    currLen+=1;
                    tempNum+=1;
                }
                len = max(currLen,len);
            }
        }
        return len;
    }
};