class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1) return strs[0];
        if(strs.size()==0) return nullptr;
        string prefix = strs[0];
        for(int i=1;i<strs.size();i++){
            string temp = "";
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j] == prefix[j]) temp += strs[i][j];
                else break;
            }
            prefix = temp;
        }
        return prefix;
    }
};