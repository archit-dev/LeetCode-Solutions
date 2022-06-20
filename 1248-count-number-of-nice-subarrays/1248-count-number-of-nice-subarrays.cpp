class Solution {
public:
    int atMostK(vector<int>& nums,int k){
        int odd = 0 , low = 0, high = 0 , count =0;
        while(high<nums.size()){
            if(nums[high]%2==1) odd+=1;
            while(low<=high && odd>k){
                if(nums[low]%2==1) odd-=1;
                low++;
            }            
            count+= high-low+1;
            high++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        //at most k odd numbers
        return atMostK(nums,k) - atMostK(nums,k-1);
    }
};