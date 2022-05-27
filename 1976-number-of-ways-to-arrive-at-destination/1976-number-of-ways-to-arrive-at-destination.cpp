#define ll long long
#define pll pair<long long, long long>
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector< pll > graph[n];
        for(int i=0;i<roads.size();i++){
            graph[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            graph[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        int mod = (1e9+7);
        vector<ll>distances(n,LLONG_MAX);
        vector<ll>ways(n,0);
        priority_queue< pll, vector< pll > ,greater<pll > > pq;
        pq.push({0,0});
        distances[0] = 0;
        ways[0] = 1;
        while(!pq.empty()){
            ll node = pq.top().second;
            ll dist = pq.top().first;
            pq.pop();
            for(auto nbr:graph[node]){
                ll nbrNode = nbr.first;
                ll wt = nbr.second;
                if(wt+dist<distances[nbrNode]){
                    distances[nbrNode] = wt+dist;
                    pq.push({distances[nbrNode],nbrNode});
                    ways[nbrNode] = ways[node];
                }else if(wt+dist==distances[nbrNode]){
                    ways[nbrNode] = (ways[nbrNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};