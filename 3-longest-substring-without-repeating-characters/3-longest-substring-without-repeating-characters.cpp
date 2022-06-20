class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int low = 0 , high = 0 , len = 0;
        while(high<s.size()){
            char curr = s[high];
            if(mp.find(curr)==mp.end()){
                mp[curr]=1;
            }else{
                while(low<high && mp[curr]!=0){
                    mp[s[low]]-=1;
                    if(mp[s[low]]==0) mp.erase(s[low]);
                    low++;
                }
                mp[curr] = 1;
            }
            len = max(len,high-low+1);
            high++;
        }
        return len;
    }
};