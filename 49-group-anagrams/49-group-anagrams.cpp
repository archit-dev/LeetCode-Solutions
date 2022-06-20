class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string> > mp;
        for(string s_:strs){
            string s = s_;
            sort(s.begin(),s.end());
            mp[s].push_back(s_);
        }
        vector<vector<string>>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};