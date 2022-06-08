class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>alpha;
        for(char x:s){
            alpha[x]+=1;
        }
        for(char x:t){
            if(alpha.find(x)==alpha.end()) return false;
            alpha[x]-=1;
        }
        for(auto &it:alpha){
            if(it.second!=0) return false; 
        }
        return true;
    }
};