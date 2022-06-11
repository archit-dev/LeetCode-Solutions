class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0,sum=0;
        unordered_map<int,int>freq;
        freq[0] = 1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int remainingSum = sum-k;
            if(freq.find(remainingSum)!=freq.end()){
                ans+=freq[remainingSum];
            }
            freq[sum]+=1;
        }
        return ans;
    }
};