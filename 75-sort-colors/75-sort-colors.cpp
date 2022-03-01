class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0,mid = 0;
        int high = n-1;
        while(mid<=high){
            if(nums[mid]==0){
                //swap mid and low and increment both
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                //swap mid and high and increment mid 
                // and decrement high
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};