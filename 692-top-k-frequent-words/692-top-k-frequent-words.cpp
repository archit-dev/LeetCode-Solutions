#define pis pair<int,string>
class myCmp {
public:
    bool operator() (const pis& a, const pis& b) {
        if(a.first==b.first) return a.second < b.second;
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string,int>mp;
        for(string &curr:words){
            mp[curr]+=1;
        }
        
        vector<string> ans(k);
        priority_queue<pis,vector<pis>,myCmp>pq;
        
        for(auto &it:mp){
            pq.push({it.second,it.first});
            if(pq.size()>k) pq.pop();
        }
        int ptr = k-1;
        while(!pq.empty()){
            ans[ptr--] = (pq.top().second);
            pq.pop();
        }
        return ans;
    }
};