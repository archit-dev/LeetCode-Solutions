class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0 , high = 0 , count = 0 , k_ = k;
        int curr = 0;
        while(high<nums.size()){
            if(nums[high]==1){
                count = max(count,high-low+1);
            }
            else{
                while(low<=high && k_==0){
                    if(nums[low]==0) k_+=1;
                    low++;
                }
                if(k_>0) k_--;
                count = max(count,high-low+1);
            }
            high++;
        }
        return count;
    }
};