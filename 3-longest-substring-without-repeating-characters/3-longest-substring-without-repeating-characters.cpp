class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0 , high = 0 ;
        int n = s.size(),ans = 0;
        unordered_map<char,int>mp;
        while(high<n){
            mp[s[high]]+=1;
            while(low<high && mp[s[high]]>1)
            {
                mp[s[low]]-=1;
                if(mp[s[low]]==0) mp.erase(s[low]);
                low+=1;
            }
            ans = max(ans, high-low+1);
            high+=1;
        }
        return ans;
    }
};