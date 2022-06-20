class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int low = 0 , high = 0;
        vector<int>ans;
        unordered_map<char,int> mp1 , mp2;
        for(char c : p) mp2[c]+=1;
        int reqMatch = p.size() , currMatch = 0;
        while(high<s.size()){
            char curr = s[high];
            if(mp2.find(curr)==mp2.end()){
                //other character, reset
                mp1.clear();
                low = high+1;
                currMatch = 0;
            }else{
                mp1[curr]+=1;
                if(mp1[curr]<=mp2[curr]) currMatch+=1;
                while(low<=high && mp1[curr]>mp2[curr]){
                    if(s[low]!=curr) currMatch-=1;
                    mp1[s[low]]-=1;
                    low++;
                }
                if(currMatch==reqMatch){
                    ans.push_back(low);
                }
            }
            high++;
        }
        return ans;
    }
};