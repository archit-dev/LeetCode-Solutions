class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int num[202] ={0};
        for(int i:nums){
            num[100+i] +=1;
        }
        int low = 0;
        for(int i=0;i<202;i++){
            if(num[i]){
                nums[low++] = i-100;
            }
        }
        return low;
    }
};