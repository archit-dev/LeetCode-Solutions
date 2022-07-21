class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp1,mp2;
        for(char x:t){
            mp1[x]+=1;
        }
        int requiredMatch = t.size(), matches = 0;
        
        int low = 0 , high = 0, n = s.size(), bestLen = INT_MAX;
        string ans = "";
        while(high<n){
            char curr = s[high];
            if(mp1.find(curr)!=mp1.end()){
                mp2[curr]+=1;
                if(mp2[curr]<=mp1[curr]) matches+=1;
                while(matches==requiredMatch){
                    if(bestLen>high-low+1){
                        bestLen = high-low+1;
                        ans = s.substr(low,bestLen);
                    }
                    if(mp1.find(s[low])!=mp1.end()){
                        //this is a valid char from second str
                        mp2[s[low]]-=1;
                        if(mp2[s[low]]<mp1[s[low]]) matches-=1;
                    }
                    low+=1;
                }
            }
            high+=1;
        }
        return ans;
    }
};