class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string remaining = countAndSay(n-1);
        string ans;
        char curr = remaining[0];
        int len = 1;
        for(int i=1;i<remaining.size();i++){
            if(remaining[i]==curr) len++;
            else{
                ans += to_string(len) + curr;
                curr = remaining[i];
                len = 1;
            }
        }
        ans+=to_string(len)+curr;
        return ans;
    }
};