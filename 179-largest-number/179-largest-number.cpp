class Solution {
public:
    static bool comparator(int a,int b){
        string first = to_string(a) + to_string(b);
        string second = to_string(b) + to_string(a);
        return first > second;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comparator);
        string ans = "";
        bool leading = true;
        for(int x:nums){
            if(x==0 && leading == true) continue;
            else{
                leading = false;
                ans+=to_string(x);
            }
        }
        if(ans.size()==0) return "0";
        return ans;
    }
};