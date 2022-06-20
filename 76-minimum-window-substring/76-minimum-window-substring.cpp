class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp1,mp2;
        for(char x:t) mp2[x]+=1;
        int reqMatch = t.size() , currMatch = 0;
        int low = 0, high = 0 , bestLen = INT_MAX;
        string ans = "";
        while(high<s.size()){
            if(mp2.find(s[high])!=mp2.end()){
                mp1[s[high]]+=1;
                if(mp1[s[high]]<=mp2[s[high]]){
                    currMatch+=1;
                }
                while(currMatch==reqMatch){
                    if(bestLen>high-low+1){
                        bestLen = high-low+1;
                        ans = s.substr(low,bestLen);
                    }
                    if(mp2.find(s[low])!=mp2.end()){
                        mp1[s[low]]-=1;
                        if(mp1[s[low]]<mp2[s[low]]){
                            currMatch-=1;
                        }
                    }
                    low++;
                }
            }
            high++;
        }
        return ans;
    }
};