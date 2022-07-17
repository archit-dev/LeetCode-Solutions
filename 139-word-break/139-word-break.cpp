class Solution {
public:
    bool helper(string& str, set<string>& st,int ptr,unordered_map<int,bool>& dp)
    {
        if(ptr==str.size()) return true;
        if(dp.find(ptr)!=dp.end()) return dp[ptr];
        string temp = "";
        for(int i=ptr;i<str.size();i++){
            temp+=str[i];
            if(st.find(temp)!=st.end()){
                if(helper(str,st,i+1,dp)){
                    return dp[ptr] = true;
                }
            }
        }
        return dp[ptr] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        for(string &temp:wordDict) st.insert(temp);
        int ptr = 0;
        unordered_map<int,bool>mp;
        return helper(s,st,ptr,mp);
    }
};