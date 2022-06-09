class Solution {
public:
    vector<string> helper(string digits,vector<string>& codes){
        if(digits.size()==0){
            vector<string> ans;
            ans.push_back("");
            return ans;
        }
        char curr = digits[0];
        string remaining = digits.substr(1);
        vector<string> ans;
        vector<string> otherCodes = helper(remaining,codes);
        for(char code:codes[curr-'0']){
            for(string currCode : otherCodes){
                ans.push_back(code+currCode);
            }
        }
        return ans;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return vector<string>(0);
        vector<string>codes(10);
        codes[2] = "abc";
        codes[3] = "def";
        codes[4] = "ghi";
        codes[5] = "jkl";
        codes[6] = "mno";
        codes[7] = "pqrs";
        codes[8] = "tuv";
        codes[9] = "wxyz";
        return helper(digits,codes);
    }
};