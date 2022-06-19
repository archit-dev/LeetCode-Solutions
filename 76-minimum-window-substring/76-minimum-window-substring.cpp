class Solution {
public:
    string minWindow(string s, string t) {
        int currentMatch = 0 , reqMatch = t.size();
        unordered_map<char,int> countT,countS;
        for(char x:t) countT[x]+=1;
        int low = 0, high = 0, bestLen = INT_MAX;
        string ans = "";
        while(high<s.size()){
            char curr = s[high];
            if(countT.find(curr)!=countT.end()){
                //this character is from string T
                countS[curr]+=1;
                if(countS[curr]<=countT[curr]){
                    currentMatch+=1;
                }
            }
            while(currentMatch==reqMatch){
                //store potential ans
                if(high-low+1<bestLen){
                    bestLen = high-low+1;
                    ans = s.substr(low,bestLen);
                }
                
                //remove the left char
                if(countT.find(s[low])!=countT.end()){
                    countS[s[low]]-=1;
                    if(countS[s[low]]<countT[s[low]]){
                        currentMatch-=1;
                    }
                }
                low++;
            }
            high++;
        }
        return ans;
    }
};