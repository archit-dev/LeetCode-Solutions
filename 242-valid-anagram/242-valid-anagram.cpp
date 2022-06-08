class Solution {
public:
    bool isAnagram(string s, string t) {
        int alpha[26]={0};
        for(char x:s){
            alpha[x-'a']+=1;
        }
        for(char x:t){
            alpha[x-'a']-=1;
        }
        for(int i=0;i<26;i++){
            if(alpha[i]!=0) return false;
        }
        return true;
    }
};