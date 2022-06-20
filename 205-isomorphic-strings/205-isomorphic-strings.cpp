class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,char> mp1,mp2;
        for(int i=0;i<s.size();i++){
            char currA = s[i];
            char currB = t[i];
            if(mp1.find(currA)==mp1.end() && mp2.find(currB)==mp2.end()){
                mp1[currA] = currB;
                mp2[currB] = currA;
            }else{
                if(mp1[currA]!=currB) return false;
                if(mp2[currB]!=currA) return false;
            }
        }
        return true;
    }
};