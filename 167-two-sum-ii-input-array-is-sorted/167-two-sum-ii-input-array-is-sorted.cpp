class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0 , high = numbers.size()-1;
        vector<int>ans(2,-1);
        while(low<high){
            int currSum = numbers[low]+numbers[high];
            if(currSum==target){
                ans[0] = low+1;
                ans[1] = high+1;
                break;
            }
            else if(currSum<target){
                low++;
            }else{
                high--;
            }
        }
        return ans;
    }
};