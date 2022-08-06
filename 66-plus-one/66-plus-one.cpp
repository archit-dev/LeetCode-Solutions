class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry = 1;
        for(int i=digits.size()-1;i>=0;i--){
            int sum = digits[i] + carry;
            if(sum>=10) carry = 1;
            else carry = 0;
            ans.push_back(sum%10);
        }
        if(carry) ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};