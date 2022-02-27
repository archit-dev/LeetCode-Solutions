class Solution {
public:
    int minSteps(string s, string t) {
        int alpha[26] = {0};
        for(char &x:s){
            alpha[x-'a'] +=1;
        }
        // print(alpha,26);
        for(char &x:t){
            alpha[x-'a'] -=1;
        }
        // print(alpha,26);
        int count = 0;
        for(int i=0;i<26;i++){
            count += abs(alpha[i]);
        }
        // print(alpha,26);
        return count;
    }
};