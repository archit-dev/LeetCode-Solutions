class Solution {
public:
    static bool cmp(string &s,string &ss){
        return s.size() < ss.size();
    }
    
    bool check(string &a,string &b){
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
    int helper(vector<string>& words,int ptr,int prev)
    {
        vector<int>dp(words.size(),1);
        //initially every word has a length 1
        for(int i=0;i<words.size();i++){
            for(int prev = 0;prev<i;prev++){
                if(check(words[prev],words[i])){
                    dp[i] = max(dp[i],1+dp[prev]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),cmp);
        return helper(words,0,-1); 
    }
};