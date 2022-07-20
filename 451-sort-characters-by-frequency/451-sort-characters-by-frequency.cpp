class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<int,int>mp;
        for(char &x:s) mp[x]+=1;
        vector<string>bucket(n+1,"");
        for(auto &it:mp){
            string temp(it.second,it.first);
            bucket[it.second]+=temp;
        }
        string ans = "";
        for(int i=n;i>=1;i--){
            if(bucket[i]!=""){
                ans+=bucket[i];
            }
        }
        return ans;
    }
};