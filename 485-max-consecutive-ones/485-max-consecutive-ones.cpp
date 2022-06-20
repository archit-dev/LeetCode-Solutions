class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int totalNum = 0 , currNum = 0;
        for(int x:nums){
            if(x==0){
                totalNum = max(totalNum,currNum);
                currNum=0;
            }else{
                currNum+=1;
            }
        }
        totalNum = max(totalNum,currNum);
        return totalNum;
    }
};