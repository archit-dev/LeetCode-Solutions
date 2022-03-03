class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int onesSoFar = 0;
        for(int &x : nums){
            if(x==1){
                onesSoFar+=1;
            }else{
                onesSoFar = 0;
            }
            ans = max(ans,onesSoFar);
        }
        return ans;
    }
};