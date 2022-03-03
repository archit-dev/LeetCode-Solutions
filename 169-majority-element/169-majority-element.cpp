class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityElement = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                majorityElement = nums[i];
            }
            if(majorityElement==nums[i]) count+=1;
            else count-=1;
        }
        return majorityElement;
    }
};