class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0, high = 0;
        int n = s.size();
        int ans = 0;
        unordered_map<char,int> alpha;
        while(high<n){
            if(alpha.find(s[high])==alpha.end()){
                //new character
            }else{
                //old character
                while(low <=high && alpha.find(s[high])!=alpha.end()){
                    alpha[s[low]]-=1;
                    if(alpha[s[low]]==0){
                        alpha.erase(s[low]);
                    }
                    low++;
                }
            }
            alpha[s[high]]+=1;
            ans = max(ans,high-low+1);
            high++;
        }
        return ans;
    }
};