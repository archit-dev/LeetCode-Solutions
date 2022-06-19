class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0, high = 0 , ans = 0 , n = nums.size();
        int k_ = k;
        while(high<n){
            if(nums[high]==1){
                high++;
            }else{
                if(k_>0){
                    high++;
                    k_-=1;
                }else{
                    ans = max(ans,high-low);
                    while(nums[low]!=0){
                        low++;
                    }
                    low++;
                    k_+=1;
                }
            }
        }
        ans = max(ans,high-low);
        return ans;
    }
};