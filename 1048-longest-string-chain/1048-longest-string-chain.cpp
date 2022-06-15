class Solution {
public:
    static bool cmp(string &s,string &ss){
        return s.size() < ss.size();
    }
    
    bool check(string& a,string& b){
        int n = a.size(), m = b.size();
        if(m-n!=1) return false;
        bool skip = false;
        int ptr1 = 0, ptr2 = 0;
        while(ptr1<n && ptr2<m){
            if(a[ptr1]==b[ptr2]){
                ptr1++;
                ptr2++;
            }else{
                if(skip) return false;
                skip = true;
                ptr2++;
            }
        }
        return true;
    }
    int helper(vector<string>& words,int ptr,int prev,
               vector<vector<int>>& dp)
    {
        if(words.size()==ptr) return 0;
        if(dp[ptr][prev+1]!=-1) return dp[ptr][prev+1];
        int exclude = 0,include = 0;
        exclude = helper(words,ptr+1,prev,dp);
        if(prev==-1 || check(words[prev],words[ptr])){
            include = helper(words,ptr+1,ptr,dp) + 1;
        }
        return dp[ptr][prev+1] = max(include,exclude);
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        sort(words.begin(),words.end(),cmp);
        return helper(words,0,-1,dp); 
    }
};