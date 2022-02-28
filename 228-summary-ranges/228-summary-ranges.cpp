class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        int start = -1, end = -1;
        bool sequence = false;
        int len = 0;
        for(int i=0;i<n;i++){
            if(!sequence){
                start = nums[i];
                sequence = true;
                len = 1; 
            }
            if(sequence){
                if((i==n-1 || nums[i]!=nums[i+1]-1) && len==1){
                    end = nums[i];
                    string temp = to_string(start);
                    ans.push_back(temp);
                    sequence = false;
                    len=0; 
                }
                else if((i==n-1 && len>1) || nums[i]!=nums[i+1]-1){
                    end = nums[i];
                    string temp = to_string(start)+"->"+to_string(end);
                    ans.push_back(temp); 
                    sequence = false;
                    len=0; 
                }else{
                    len++; 
                }
            }
        }
        return ans;
    }
};