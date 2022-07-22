class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        for(string &s:words) mp[s]+=1;
        int n = words.size();
        vector<vector<string>>freq(n+1);
        for(auto &it:mp){
            freq[it.second].push_back(it.first);
        }
        vector<string>ans;
        for(int i=n;i>0;i--){
            for(int j=0;j<freq[i].size();j++){
                ans.push_back(freq[i][j]);
                if(ans.size()==k) break;
            }
            if(ans.size()==k) break;
        }
        return ans;
    }
};