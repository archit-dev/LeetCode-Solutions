class Solution {
public:
    bool match(vector<int>& freq1 , vector<int>& freq2){
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        int n1 = s1.size() , n2 = s2.size();
        int low = 0 , high = 0;
        while(high<n1){
            freq1[s1[high]-'a']+=1;
            freq2[s2[high]-'a']+=1;
            high+=1;
        }
        
        if(match(freq1,freq2)) return true;
        
        while(high<n2){
            freq2[s2[high]-'a']+=1;
            freq2[s2[low]-'a']-=1;
            low+=1;
            high+=1;
            if(match(freq1,freq2)) return true;
        }
        
        return false;
    }
};