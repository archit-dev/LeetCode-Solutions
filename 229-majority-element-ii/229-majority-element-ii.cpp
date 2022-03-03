class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int ele1 = INT_MIN , ele2 = INT_MIN, count1 = 0 , count2 = 0, n = nums.size();
        for(int &x : nums){
            if(x==ele1) count1++;
            else if(x==ele2) count2++;
            else if(count1==0){
                count1++;
                ele1 = x;
            }else if(count2==0){
                count2++;
                ele2 = x;
            }else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0 ;
        for(int &x:nums){
            if(x==ele1) count1++;
            if(x==ele2) count2++;
        }
        if(count1>n/3) ans.push_back(ele1);
        if(count2>n/3) ans.push_back(ele2);
        return ans;
    }
};