class Solution {
public:
    
    int check(vector<int>& nums,int m,int ans){
        int ptr = 0;
        int sum = 0;
        int numberOfSubArrays = 1;
        while(ptr!=nums.size()){
            if(nums[ptr]+sum<=ans){
                sum += nums[ptr];
                ptr++;
            }else{
                numberOfSubArrays++;
                sum=0;
            }
        }
        return numberOfSubArrays;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int low = *max_element(nums.begin(),nums.end());
        int high = 0;
        for(int &x:nums) high += x;
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(nums,m,mid)<=m){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};