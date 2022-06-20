class Solution {
public:
    //concept similar to isomorphic stirngs
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp1;
        unordered_map<string,char> mp2;
        int ptr = 0;
        vector<string> strings;
        string mapStr = "";
        while(ptr<s.size()){
            while(ptr<s.size() && s[ptr]!=' '){
                mapStr+=s[ptr];
                ptr++;
            }
            strings.push_back(mapStr);
            mapStr= "";
            ptr++;
        }
        if(pattern.size() != strings.size()) return false;
        for(int i=0;i<pattern.size();i++){
            char curr = pattern[i];
            if(mp1.find(curr)==mp1.end() && mp2.find(strings[i])==mp2.end()){
                mp1[curr] = strings[i];
                mp2[strings[i]] = curr;
             }else{
                if(mp1[curr]!=strings[i]) return false;
                if(mp2[strings[i]]!=curr) return false;
            }
        }
        return true;
    }
};