class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        bool brk = true;
        for(int i=0;i<s1.size();i++){
            if(s1[i]<s2[i]){
                brk = false;
                break;
            }
        }
        if(brk) return true;
        brk = true;
        for(int i=0;i<s1.size();i++){
            if(s2[i]<s1[i]){
                return false;
            }
        }
        return true;
    }
};