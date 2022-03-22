class Solution {
public:
    #define pii pair<int, vector<int> >
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // priority_queue<pii, vector<pii>, greater<pii> > pq;
        priority_queue<pii> pq;
        for(auto &it:points){
            int x = it[0];
            int y = it[1];
            int dist = x*x + y*y;
            pq.push({dist,it});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int> > ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};