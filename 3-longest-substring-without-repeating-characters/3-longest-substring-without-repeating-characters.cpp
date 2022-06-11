class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int ans = 0;
        int ptr1 = 0, ptr2 = 0;
        while(ptr2<s.size()){
            //keep acquiring until it becomes invalid
            char current = s[ptr2];
            if(mp.find(current)==mp.end()){
                //not found yet
                mp[current]+=1;
            }else{
                //this character has been found before
                //so now keep removing from the start
                //until the hashmap becomes valid again
                mp[current]+=1;
                while(ptr1<s.size() && mp[current]!=1){
                    mp[s[ptr1]]-=1;
                    ptr1++;
                }
            }
            ans = max(ans,ptr2-ptr1+1);
            ptr2++;
        }
        return ans;
    }
};