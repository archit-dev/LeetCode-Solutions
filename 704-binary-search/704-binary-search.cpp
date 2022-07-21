class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0 , high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(target==nums[mid]){
                return mid;
            }
            else if(nums[mid] < target){
                low+=1;
            }else{
                high-=1;
            }
        }
        return -1;
    }
};