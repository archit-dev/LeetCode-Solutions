class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,char> mp;
        for(int i=0;i<s.size();i++){
            char curr = s[i];
            if(mp.find(curr)==mp.end()){
                mp[curr] = t[i];
            }else{
                if(mp[curr]!=t[i]) return false;
            }
        }
        mp.clear();
        for(int i=0;i<t.size();i++){
            char curr = t[i];
            if(mp.find(curr)==mp.end()){
                mp[curr] = s[i];
            }else{
                if(mp[curr]!=s[i]) return false;
            }
        }
        return true;
    }
};