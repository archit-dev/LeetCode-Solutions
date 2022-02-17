class Solution { 
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2=0;
        int prev1=0;
        for(int i=1;i<=n;i++){
            int incl = nums[i-1];
            int excl = 0;
            if(i-1>=0){
                excl = prev1;
            }
            if(i-2>=0){
                incl = nums[i-1] + prev2;
            }
            int ans = max(incl,excl);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
};