class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currentOnes = 0, finalAns = 0 ;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                finalAns = max(currentOnes,finalAns);
                currentOnes = 0;
            }
            else currentOnes++;
        }
        finalAns = max(currentOnes,finalAns);
        return finalAns;
    }
};