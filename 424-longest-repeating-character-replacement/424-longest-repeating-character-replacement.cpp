class Solution {
public:
    int characterReplacement(string s, int k) {
        int low = 0 , high = 0 , ans = 0;
        vector<int>freq(26,0);
        while(high<s.size()){
            freq[s[high]-'A']+=1;
            int windowSize = high-low+1;
            int maxFreq = *max_element(freq.begin(),freq.end());
            if(windowSize-maxFreq<=k){
                ans = max(ans,windowSize);
            }else{
                while(windowSize-maxFreq>k){
                    freq[s[low]-'A']-=1;
                    maxFreq = *max_element(freq.begin(),freq.end());
                    low+=1;
                    windowSize-=1;
                }
                ans = max(ans,windowSize);
            }
            high+=1;
        }
        return ans;
    }
};