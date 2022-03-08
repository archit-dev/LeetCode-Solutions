class Solution {
public:
    void solve(string s,int idx,string stringSoFar,vector<string> &ans){
        if(idx<0){
            ans.push_back(stringSoFar);
            return;
        }
        if(s[idx]>='0' && s[idx]<='9'){
            return solve(s,idx-1,s[idx]+stringSoFar,ans);
        }
        bool lowerCase = false;
        if(s[idx]>='a' && s[idx]<='z') lowerCase = true;
        char currentChar=s[idx];
        char lowercase = currentChar;
        char uppercase = currentChar;
        if(lowerCase) uppercase = toupper(currentChar);
        else lowercase = tolower(currentChar);
        solve(s,idx-1,lowercase+stringSoFar,ans);
        solve(s,idx-1,uppercase+stringSoFar,ans);
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(s,s.size()-1,"",ans);
        return ans;
    }
};